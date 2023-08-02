# Hyperloop_Passenger_Booking

OOPS concept is used in this program.
There are 4 Command in this program:
INIT
ADD_PASSENGER 
START_POD 
PRINT_Q

Each command in this program is coded in seperate function. Sequence of instruction or data is stored under the single name inside the structure.

INIT Command
Initializes the system with Number of interconnecting routes (N) and the Starting station.
Next N lines denotes connection between two interconnections and their distance.
	Without initializing - all other commands should throw proper error.

ADD_PASSENGER command adds passengers to the line.
ADD_PASSENGER X adds X number of passengers to the line. X lines following the ADD command denote the passenger's name, age and destination
NAME AGE DEST

START_POD command starts pod with a passenger having highest age to his destination following the minimum interconnection points. Print the passenger name and route.
START_POD X starts X number of passengers of oldest age. (X lines are printed with name and route )
NAME ROUTE

PRINT_Q command prints the number of passengers and their details who are remaining in the queue.
COUNT
NAME AGE

when selecting each command in the main function, appropriate sub function is called. Global variable of each structure store the sequence of data.


