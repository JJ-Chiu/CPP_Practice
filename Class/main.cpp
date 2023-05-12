#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>

using namespace std;

class Time
{
private:
    static bool h12;
    int hour;
    int minute;
    int second;

public:
    // Event class will raise a compiler error that it need a default constructor of Time class, 
    // Default constructor is a constructor without any parameter.
    // 
    // There are two options to fix the issue.
    // Option 1. Give default value to our parameters constructor.
    Time(int h = 0, int m = 0, int s = 0);
    // Option 2. Tell the compiler to do what it would have if we didn't define any parameters.
    // Time() = default;

    static void print12Hour(bool);

    void print();
    bool isEarlierThan(Time t);
    void printNicely();
    string toString();
};

Time::Time(int h, int m, int s)
{
    hour = h;
    minute = m;
    second = s;
}

void Time::print12Hour(bool enable12hFormat)
{
    h12 = enable12hFormat;
}

string Time::toString()
{
    stringstream ss;
    const string SPACE = " ";
    int h = hour, m = minute, s = second;
    string hFormat = "";
    if (Time::h12) {
        hFormat = h < 12 ? "AM" : "PM";
        h = h > 12 ? h - 12 : h; 
    }
    ss << setw(2) << setfill('0') << h << ":"
         << setw(2) << setfill('0') << m << ":"
         << setw(2) << setfill('0') << s << SPACE << hFormat;

    return ss.str();
}

void Time::print()
{
    cout << hour << ":"
         << minute << ":"
         << second << endl;
}

bool Time::isEarlierThan(Time t)
{
    if (hour < t.hour)
        return true;
    if (minute < t.minute)
        return true;
    if (second < t.second)
        return true;
    return false;
}

void Time::printNicely()
{
    const string SPACE = " ";
    int h = hour, m = minute, s = second;
    string hFormat = "";
    if (Time::h12) {
        hFormat = h < 12 ? "AM" : "PM";
        h = h > 12 ? h - 12 : h; 
    }
    cout << setw(2) << setfill('0') << h << ":"
         << setw(2) << setfill('0') << m << ":"
         << setw(2) << setfill('0') << s << SPACE << hFormat << endl;
}

bool Time::h12 = false;

class Event
{
private:
    static const string defaultName;
    string name;
    Time start;
    Time end;

public:
    Event(string n, Time s, Time e);
    Event() = default;
    //~Event();
    void printNicely();
    void setName(string n);
};

const string Event::defaultName = "No Name";

Event::Event(string n, Time s, Time e)
{
    name = n;
    start = s;
    end = e;
}

void Event::printNicely()
{
    cout << name << endl;
    cout << "Start: " + start.toString() << endl;
    cout << "End: " + end.toString() << endl; 
}

void Event::setName(string n)
{
    name = n;
}

int main()
{
    char n1[] = "PD";
    Event e1(n1, Time(14, 20, 0),
             Time(17, 20, 0));
    Event *schedule = new Event[10];
    schedule[0] = e1;
    delete[] schedule;
    return 0;
}
