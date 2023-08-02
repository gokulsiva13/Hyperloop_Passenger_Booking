# Hyperloop_Passenger_Booking

I have used OOPS concept to run this program. I have created a function for each commands:

INIT
ADD_PASSENGER 
START_POD 
PRINT_Q

I have created a structure for each command to store the data in the following manner. so the data's were stored in the array.


INIT Command  - Initializes the system with
Number of interconnecting routes (N) and the Starting station.
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

