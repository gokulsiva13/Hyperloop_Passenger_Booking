#include <iostream>
#include <cstring>
using namespace std;
const int maximumpassengers = 100;
const int maximumroutes = 100;
struct PassengerDetails 
{
    string name;
    int age;
    string destination;
};
int passengerCount = 0;
PassengerDetails passengerQ[maximumpassengers];
struct Route 
{
    string station1;
    string station2;
    int distance;
};
int routeCount = 0;
Route routesQ[maximumroutes];
struct Pod 
{
    string passengerName;
    string ro;
};
int podCount = 0;
Pod podQ[maximumpassengers];


void INIT(int N, string startStation) 
{
    routeCount = N;
    cout << "No of routes" << N << " starting from " << startStation << endl;
}


void ADD_PASSENGER(int numofPassengers) 
{
    for (int i = 0; i < numofPassengers; ++i)
    {
        PassengerDetails passenger;
        cin >> passenger.name >> passenger.age >> passenger.destination;
        passengerQ[passengerCount++] = passenger;
    }
}


void PRINT_Q()
{
    cout << "Number of passengers in the queue: " << passengerCount << endl;
    for (int i = 0; i < passengerCount; ++i) 
    {
        cout << passengerQ[i].name << " " << passengerQ[i].age << " " << passengerQ[i].destination <<endl;
    }
}


void START_POD(int numofPassengers) 
{
    if (passengerCount == 0) 
    {
        cout << "No passengers in the queue to start the pod" << endl;
        return;
    }
    
    int oldestPassengernumber = -1;
    int oldestAge = -1;
    for (int i = 0; i < passengerCount; ++i) 
    {
        if (passengerQ[i].age > oldestAge) 
        {
            oldestAge = passengerQ[i].age;
            oldestPassengernumber = i;
        }
    }
    PassengerDetails oldestPassenger = passengerQ[oldestPassengernumber];
    
    int min = 1000;
    string route;
    for (int i = 0; i < routeCount; ++i)
    {
        if (routesQ[i].station1 == oldestPassenger.destination || routesQ[i].station2 == oldestPassenger.destination)
        {
            int mid = 0;
            if (routesQ[i].station1 == oldestPassenger.destination)
            {
                mid++;
                for (int j = 0; j < routeCount; ++j)
                {
                    if (routesQ[j].station1 == routesQ[i].station2 || routesQ[j].station2 == routesQ[i].station2)
                    {
                        mid++;
                        break;
                    }
                }
            } 
            else
            {
                mid++;
                for (int j = 0; j < routeCount; ++j)
                {
                    if (routesQ[j].station1 == routesQ[i].station1 || routesQ[j].station2 == routesQ[i].station1) 
                    {
                        mid++;
                        break;
                    }
                }
            }

            if (mid < min) 
            {
                min = mid;
                route = routesQ[i].station1 + " to " + routesQ[i].station2;
            }
        }
    }

    Pod pod;
    pod.passengerName = oldestPassenger.name;
    pod.ro = route;
    podQ[podCount++] = pod;
    cout << pod.passengerName << " " << pod.ro << " "  <<endl;

    for (int i = oldestPassengernumber; i < passengerCount - 1; ++i)
    {
        passengerQ[i] = passengerQ[i + 1];
    }
    passengerCount--;
}

int main() 
{
    char access[20];
    int N,a=0;
    string startStation;
    cout<<"Enter 'INIT' to Initialize the system"<<endl;
    
   while(a==0)
   {
       cin>>access;
        if (strcmp(access, "INIT") == 0) 
        {
            a=1;
        }
        else
        {
            cout<<"invalid"<<endl;
        }
    }
    cout<<"Enter number of Interconnecting routes and starting station"<<endl;
    cin >> N >> startStation;
    INIT(N, startStation);
    cout<<"Enter station_1 station_2 and distance for"<<N <<"connection"<<endl;
    for (int i = 0; i < N; ++i) 
    {
        string station1, station2;
        int distance;
        cin >> station1 >> station2 >> distance;
        routesQ[i] = {station1, station2, distance};
    }
    while (true)
    {
        char command[20];
        cout<<"Enter commands"<<endl;
        cout<<"ADD_PASSENGER     START_POD     PRINT_Q"<<endl;
        cin >> command;

        if (strcmp(command, "ADD_PASSENGER") == 0) 
        {
            int numofPassengers;
            cin >> numofPassengers;
            ADD_PASSENGER(numofPassengers);
        } 
        else if (strcmp(command, "START_POD") == 0)
        {
            int numofPassengers;
            cin >> numofPassengers;
            START_POD(numofPassengers);
        } 
        else if (strcmp(command, "PRINT_Q") == 0)
        {
            PRINT_Q();
        } 
        else
        {
            cout << "Invalid command. Please try again." << endl;
        }
    }
    return 0;
}