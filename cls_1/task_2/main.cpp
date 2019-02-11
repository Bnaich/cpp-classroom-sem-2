#include "schedule.hpp"

#include <cassert>
#include <algorithm>


void test_no_rooms() {
    DaySchedule schedule;

    assert(!schedule.TryAdd({}));

    Event ev("discuss", 42, 43200, 3600);
    // throw exception
    assert(!schedule.TryAdd(ev));
}


void test_correct_planning() {
    DaySchedule schedule({42});

    Event ev("discuss", 42, 43200, 3600);
    assert(schedule.TryAdd(ev));

    Event ev2("discuss2", 42, 32400, 3600);
    assert(schedule.TryAdd(ev2));
}


void test_no_free_rooms() {
    DaySchedule schedule({42});

    Event ev("discuss", 42, 43200, 3600);
    assert(schedule.TryAdd(ev));

    Event ev2("discuss2", 42, 43000, 3600);
    assert(!schedule.TryAdd(ev2));
}


void test_different_rooms() {
    DaySchedule schedule({42, 24});

    Event ev("discuss", 42, 43200, 3600);
    assert(schedule.TryAdd(ev));

    Event ev2("discuss2", 24, 43000, 3600);
    assert(schedule.TryAdd(ev2));
}

void test_get_planned_events() {
    DaySchedule schedule({42, 12, 24});

    Event ev("discuss", 42, 43200, 3600);
    schedule.TryAdd(ev);

    Event ev2("discuss2", 24, 41400, 7200);
    schedule.TryAdd(ev2);

    Event ev3("discuss3", 24, 32400, 3600);
    schedule.TryAdd(ev3);

    Event ev4("discuss4", 12, 45000, 3600);
    schedule.TryAdd(ev4);

    auto plannedEventIt = schedule.GetPlannedEvents(45000);
    std::vector<Events> expectedPlannedEvents(ev4, ev2, ev);

    assert(std::equal(expectedPlannedEvents.cbegin(), expectedPlannedEvents.cend(), plannedEventIt));
}


int main() {
    test_no_rooms();
    test_correct_planning();
    test_no_free_rooms();
    test_different_rooms();
    test_get_planned_events();

    return 0;
}
