#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <iomanip>
#include <vector>
#include <cstdlib> // مكتبة Random
#include <ctime>   // مكتبة Time

using namespace std;

// Base Class: Timer (Encapsulation, Access Modifiers, Virtual Functions)
class Timer {
protected:
    string title;
    int totalSeconds;

public:
    Timer(string t, int mins) {
        title = t;
        totalSeconds = mins * 60;
    }

    // Function Overloading 1
    void setTime(int mins) {
        totalSeconds = mins * 60;
    }

    // Function Overloading 2
    void setTime(int mins, int secs) {
        totalSeconds = (mins * 60) + secs;
    }

    virtual ~Timer() {}

    // Pure Virtual Function
    virtual void start() = 0;

    string getTitle() const {
        return title;
    }
};

// Derived Class: PomodoroTimer
class PomodoroTimer : public Timer {
private:
    int breakMinutes;
    vector<string> quotes; // مصفوفة النصائح التحفيزية

public:
    PomodoroTimer(string t, int workMins, int breakMins) 
        : Timer(t, workMins), breakMinutes(breakMins) {
        
        // قائمة نصائح عشوائية
        quotes = {
            "Keep going! Small steps lead to big results. 💪",
            "Focus on being productive instead of busy. 🎯",
            "Believe you can and you're halfway there. ✨",
            "Your future self will thank you for today's effort! 🚀"
        };
    }

    ~PomodoroTimer() {
        cout << "\n[System] Pomodoro Session destroyed safely." << endl;
    }

    // عرض نصيحة عشوائية باستخدام Random
    void showRandomQuote() {
        int randomIndex = rand() % quotes.size(); // اختيا عشوائي
        cout << "\n💡 Motivational Quote: " << quotes[randomIndex] << "\n" << endl;
    }

    void start() override {
        cout << "\n========================================" << endl;
        cout << " ⏳ Starting Work Session: " << title << endl;
        cout << "========================================" << endl;

        showRandomQuote(); // استدعاء النصيحة العشوائية

        int currentSeconds = totalSeconds;
        while (currentSeconds > 0) {
            int mins = currentSeconds / 60;
            int secs = currentSeconds % 60;

            cout << "\r ⏲ Time Remaining: " 
                 << setfill('0') << setw(2) << mins << ":" 
                 << setfill('0') << setw(2) << secs << flush;

            this_thread::sleep_for(chrono::seconds(1));
            currentSeconds--;
        }

        cout << "\n\n🔔 Time's UP! Work session finished." << endl;
        startBreak();
    }

private:
    void startBreak() {
        cout << "\n☕ Starting Break (" << breakMinutes << " mins)..." << endl;
        int breakSecs = breakMinutes * 60;
        while (breakSecs > 0) {
            int mins = breakSecs / 60;
            int secs = breakSecs % 60;

            cout << "\r 🛑 Break Remaining: " 
                 << setfill('0') << setw(2) << mins << ":" 
                 << setfill('0') << setw(2) << secs << flush;

            this_thread::sleep_for(chrono::seconds(1));
            breakSecs--;
        }
        cout << "\n✨ Break is over! Ready for the next session." << endl;
    }
};

// Main Function
int main() {
    // تهيئة الـ Random بالوقت الحالي
    srand(time(0));

    cout << "==========================================" << endl;
    cout << "   Welcome to OOP Pomodoro Manager (C++)  " << endl;
    cout << "==========================================" << endl;

    string title;
    int workMins, breakMins;

    cout << "Enter Task Title: ";
    getline(cin, title);

    cout << "Enter Work Time (minutes): ";
    cin >> workMins;

    cout << "Enter Break Time (minutes): ";
    cin >> breakMins;

    // Polymorphic object setup
    Timer* myTimer = new PomodoroTimer(title, workMins, breakMins);
    myTimer->start();

    delete myTimer; // Clean memory
    return 0;
}
