#pragma once

#include <iostream>
#include <vector>
#include "clsDate.h"
using namespace std;

class clsPeriod {
private:
    clsDate _Start, _End;

public:
    clsPeriod() {};

    clsPeriod(clsDate Start, clsDate End) {
        _Start = Start;
        _End = End;
    }
    
    clsPeriod(string StartPeriod /*"YYYY/MM/DD"*/, string EndPeriod /*"YYYY/MM/DD"*/, string StartSeperator = "/", string EndSeperator = "/") {
        _Start = clsDate(StartPeriod, StartSeperator);
        _End = clsDate(EndPeriod, EndSeperator);
    }

    void setStartPeriod(short Year, short Month, short Day) {
        _Start.setYear(Year);
        _Start.setMonth(Month);
        _Start.setDay(Day);
    }

    void setStartPeriod(clsDate Start) {
        _Start = Start;
    }

    clsDate getStartPeriod() {
        return _Start;
    }

    void setEndPeriod(short Year, short Month, short Day) {
        _Start.setYear(Year);
        _Start.setMonth(Month);
        _Start.setDay(Day);
    }

    void setEndPeriod(clsDate End) {
        _End = End;
    }

    clsDate getEndPeriod() {
        return _End;
    }

    /// @brief check if period1 and period2 are overlaping
    static bool ArePeriodsOverlap(clsPeriod Period1, clsPeriod Period2) {
        if (clsDate::CompareDates(Period2.getStartPeriod(), Period1.getEndPeriod()) == clsDate::enDatesCompare::eAfter || clsDate::CompareDates(Period2.getEndPeriod(), Period1.getStartPeriod()) == clsDate::enDatesCompare::eBefore) {
            return false;
        }
        return true;
    }
    
    /// @brief calculate the number of days in the period
    /// @param IncludeEndDte the option if you want to include the end day or the last day of the period
    static short PeriodLength(clsPeriod Period, bool IncludeEndDte = false) {
        return clsDate::DifferentInDays(Period.getStartPeriod(), Period.getEndPeriod(), IncludeEndDte);
    }

    short PeriodLength(bool IncludeEndDte = false) {
        return PeriodLength(*this, IncludeEndDte);
    }

    static bool IsDateInPeriod(clsPeriod Period, clsDate Date) {
        return !(clsDate::CompareDates(Date, Period.getStartPeriod()) == clsDate::enDatesCompare::eBefore || clsDate::CompareDates(Date, Period.getEndPeriod()) == clsDate::enDatesCompare::eAfter);
    }

    bool IsDateInPeriod(clsDate Date) {
        return !(clsDate::CompareDates(Date, _Start) == clsDate::enDatesCompare::eBefore || clsDate::CompareDates(Date, _End) == clsDate::enDatesCompare::eAfter);
    }

    static void Swap(clsPeriod& Period1, clsPeriod& Period2) {
        clsPeriod TempPeriod = Period1;
        Period1 = Period2;
        Period2 = TempPeriod;
    }


    // int OverlapDaysIn2Periods(clsPeriod Period1, clsPeriod Period2) {
    //     if (!ArePeriodsOverlap(Period1, Period2)) {
    //         return 0;
    //     }
    //     clsDate StartPeriod1 = Period1.getStartPeriod();
    //     clsDate EndPeriod1 = Period1.getEndPeriod();
    //     clsDate StartPeriod2 = Period2.getStartPeriod();
    //     clsDate EndPeriod2 = Period2.getEndPeriod();

    //     int Period1Length = PeriodLength(Period1, true);
    //     int Period2Length = PeriodLength(Period2, true);
    //     int OverlapDays = 0;

    //     if (Period1Length < Period2Length) {
    //         while (IsDate1BeforeDate2(StartPeriod1, EndPeriod1)) {
    //             if(IsDateInPeriod(Period2, StartPeriod1)) {
    //                 OverlapDays++;
    //             }
    //             StartPeriod1 = IncreaseByOneDay(StartPeriod1);
    //         }
    //     }
    //     else if (Period1Length > Period2Length) {
    //         while (IsDate1BeforeDate2(StartPeriod2, EndPeriod2)) {
    //             if(IsDateInPeriod(Period1, StartPeriod2)) {
    //                 OverlapDays++;
    //             }
    //             StartPeriod2 = IncreaseDateByOne(StartPeriod2);
    //         }
    //     }
    //     return OverlapDays;
    // }


    // int OverlapDaysIn2Periods(clsPeriod Period1, clsPeriod Period2) {
    //     if (!ArePeriodsOverlap(Period1, Period2)) {
    //         return 0;
    //     }
    //     if (PeriodLength(Period1, true) > PeriodLength(Period2, true)) {
    //         Swap(Period1, Period2);
    //     }
    //     clsDate StartPeriod1 = Period1.getStartPeriod();
    //     clsDate EndPeriod1 = Period1.getEndPeriod();
    //     int OverlapDays = 0;

    //     while (IsDate1BeforeDate2(StartPeriod1, EndPeriod1)) {
    //         if(IsDateInPeriod(Period2, StartPeriod1)) {
    //             OverlapDays++;
    //         }
    //         StartPeriod1 = IncreaseByOneDay(StartPeriod1);
    //     }
    //     return OverlapDays;
    // }

    static int OverlapDaysIn2Periods(clsPeriod Period1, clsPeriod Period2) {
        clsDate StartPeriod1 = Period1.getStartPeriod();
        clsDate EndPeriod1 = Period1.getEndPeriod();
        clsDate StartPeriod2 = Period2.getStartPeriod();
        clsDate EndPeriod2 = Period2.getEndPeriod();

        if (!ArePeriodsOverlap(Period1, Period2)) {
            return 0;
        }
        clsDate OverlapStart = (clsDate::IsDate1BeforeDate2(StartPeriod1, StartPeriod2))? StartPeriod1 : StartPeriod2;
        clsDate OverlapEnd = (clsDate::IsDate1BeforeDate2(EndPeriod1, EndPeriod2))? EndPeriod1 : EndPeriod2;

        return clsDate::DifferentInDays(OverlapStart, OverlapEnd, true);
    }

    int OverlapDaysIn2Periods(clsPeriod Period2) {
        return OverlapDaysIn2Periods(*this, Period2);
    }
};