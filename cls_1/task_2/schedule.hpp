#include <string>
#include <set>


using RoomType = uint16_t;
using TimeType = uint32_t;


class Event {
    Event(std::string name, RoomType room_number, TimeType start_time, TimeType duration);

    bool operator==(const Event& other);

    // getters...

public:
    std::string name_;
    RoomType room_number_;
    TimeType start_time_;
    TimeType duration_;
};


class DaySchedule {
public:
    class PlannedEventsIt;

public:
    explicit DaySchedule(std::set<RoomType> rooms);

    // throws on incorrect event
    bool TryAdd(const Event& event);

    std::pair<PlannedEventsIt, PlannedEventsIt> GetPlannedEvents(TimeType time);  // sorted by room numbers

    // ...
};
