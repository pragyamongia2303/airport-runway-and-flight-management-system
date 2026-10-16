#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

struct Flight
{
    string flightNumber;
    string flightName;
    string arrivalTime;
    string departureTime;

    int fuel;
    int distance;

    int priority;
    string priorityName;

    int entryOrder;
};

struct ComparePriority
{
    bool operator()(Flight a, Flight b)
    {

        if (a.priority != b.priority)
        {
            return a.priority > b.priority;
        }

        if (a.fuel != b.fuel)
        {
            return a.fuel > b.fuel;
        }

        if (a.distance != b.distance)
        {
            return a.distance < b.distance;
        }

        return a.entryOrder > b.entryOrder;
    }
};

int main()
{

    Flight flights[20];
    int n;

    cout << "   AIRPORT RUNWAY AND FLIGHT MANAGEMENT\n";

    cout << "Enter number of flights: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details for Flight " << i + 1 << ":\n";

        cout << "Flight Number: ";
        cin >> flights[i].flightNumber;

        cout << "Flight Name: ";
        cin.ignore();
        getline(cin, flights[i].flightName);

        cout << "Time of Arrival: ";
        cin >> flights[i].arrivalTime;

        cout << "Time of Departure: ";
        cin >> flights[i].departureTime;

        cout << "Fuel Amount (litres): ";
        cin >> flights[i].fuel;

        cout << "Distance Travelled (km): ";
        cin >> flights[i].distance;

        cout << "\nSelect Priority:\n";
        cout << "1. Medical Emergency\n";
        cout << "2. Less Fuel\n";
        cout << "3. VIP Visit\n";
        cout << "4. Normal Flight\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;

        if (choice == 1)
        {
            flights[i].priority = 1;
            flights[i].priorityName = "Medical Emergency";
        }
        else if (choice == 2)
        {
            flights[i].priority = 2;
            flights[i].priorityName = "Less Fuel";
        }
        else if (choice == 3)
        {
            flights[i].priority = 3;
            flights[i].priorityName = "VIP Visit";
        }
        else
        {
            flights[i].priority = 4;
            flights[i].priorityName = "Normal Flight";
        }

        flights[i].entryOrder = i;
    }

    priority_queue<Flight, vector<Flight>, ComparePriority> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push(flights[i]);
    }

    queue<Flight> runwayQueue;

    stack<Flight> completedFlights;

    cout << "          RUNWAY ALLOCATION ORDER\n";

    while (!pq.empty())
    {
        Flight current = pq.top();
        pq.pop();

        runwayQueue.push(current);
    }

    int runwayNumber = 1;

    while (!runwayQueue.empty())
    {
        Flight current = runwayQueue.front();
        runwayQueue.pop();

        cout << "\nRunway " << runwayNumber << " Assigned";
        cout << "\nFlight Number   : " << current.flightNumber;
        cout << "\nFlight Name     : " << current.flightName;
        cout << "\nArrival Time    : " << current.arrivalTime;
        cout << "\nDeparture Time  : " << current.departureTime;
        cout << "\nFuel Amount     : " << current.fuel << " litres";
        cout << "\nDistance        : " << current.distance << " km";
        cout << "\nPriority        : " << current.priorityName;

        completedFlights.push(current);

        runwayNumber++;

        if (runwayNumber > 2)
            runwayNumber = 1;
    }

    cout << "       COMPLETED FLIGHTS (STACK)\n";

    while (!completedFlights.empty())
    {
        Flight current = completedFlights.top();
        completedFlights.pop();

        cout << current.flightNumber
             << " - " << current.flightName
             << " - Completed\n";
    }

    cout << "       FLIGHT MANAGEMENT COMPLETED\n";

    return 0;
}