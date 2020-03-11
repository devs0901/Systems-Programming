#!/bin/bash

# Use $cal function to display current date and time
# The $cal command displays a simple calendar in traditional formal
# The $ncal does the same in an alternative layout
# If the arguments are not specified, the current month is displayed

# To run Task 1
	# Current month
	# ./cal2.sh
	# Current year with arg1 - month 1
	# ./cal2.sh 1
	# Arg1 as 5 and arg2 as 2001 - month 5 year 2001
	# ./cal2.sh 5 2001

case $# in 
# $# represents the number of arguments the user inputs

	0) #if 0 input
		cal ;;

	1) #if 1 arg
		cal -m$1 ;;
		# -m[arg1] must be used in order to specify month
		# if not, it will treat the input as a year
		# and will print out the full calendar of that year

	2) #if 2 argument, note that arg2 must be XXXX
		cal $1 $2 ;;
esac

		
