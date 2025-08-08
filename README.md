# Periods_Library
clsPeriod is a C++ class that represents a date range using a start and end date. It provides methods to calculate the period length, check if dates fall within the range, detect overlaps with other periods, and count overlapping days.

## Overview

The **clsPeriod** class is a utility class in C++ designed to handle operations related to a period between two dates. It depends on the **clsDate** class and provides features like:

* Defining a period between two dates
* Checking if two periods overlap
* Calculating the number of days in the period
* Checking if a specific date is within a period
* Calculating overlap days between two periods

---

## Dependencies

* **clsDate**  
---

## Constructors

* **clsPeriod();** *Default constructor*

* **clsPeriod(clsDate Start, clsDate End);** *Using clsDate objects*

* **clsPeriod(string StartPeriod, string EndPeriod, string StartSeperator = "/", string EndSeperator = "/");** *From string dates like "2025/06/01"*

---

## Setter & Getter

* **void setStartPeriod(short Year, short Month, short Day);**
* **void setStartPeriod(clsDate Start);**
* **clsDate getStartPeriod();**

* **void setEndPeriod(short Year, short Month, short Day);**
* **void setEndPeriod(clsDate End);**
* **clsDate getEndPeriod();**

---

## Core Methods

* **static bool ArePeriodsOverlap(clsPeriod Period1, clsPeriod Period2);**
* **static short PeriodLength(clsPeriod Period, bool IncludeEndDte = false);**
* **static bool IsDateInPeriod(clsPeriod Period, clsDate Date);**
* **static void Swap(clsPeriod& Period1, clsPeriod& Period2);**
* **static int OverlapDaysIn2Periods(clsPeriod Period1, clsPeriod Period2);**
* **short PeriodLength(bool IncludeEndDte = false);**
* **bool IsDateInPeriod(clsDate Date);**
* **int OverlapDaysIn2Periods(clsPeriod Period2);**

---

## Author

**Marsileno Medhat** 

**June 2025**
