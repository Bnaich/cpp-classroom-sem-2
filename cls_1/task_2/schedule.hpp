#include <string>
#include <set>


class Event {
    Event(std::string name, uint8_t room_number, uint8_t start_time, uint8_t duration);

    bool operator==(const Event& other);

    // getters...

public:
    std::string name_;
    uint8_t room_number_;
    uint8_t start_time_;
    uint8_t duration_;
};


class DaySchedule {
public:
    class PlannedEventsIt;

public:
    explicit DaySchedule(std::set<uint8_t> rooms);

    // throws on incorrect event
    bool TryAdd(const Event& event);

    std::pair<PlannedEventsIt, PlannedEventsIt> GetPlannedEvents(uint8_t time);  // sorted by room numbers

    // ...
};
