# Project Overview

## Problem
Air traffic needs to be scheduled by urgency, not arrival time.

## Approach
A priority queue orders flights: Emergency > Low fuel > VIP > Normal.

## Data Structures
- Priority queue: picks the next flight
- Runway queue: flights waiting to use the runway
- Completed stack: flights already handled

## Limitations
Weather, aircraft separation and changing priorities are not covered.
