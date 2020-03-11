#!/bin/bash

	#To run Task 2
		# No argument - print you must provide one
		# 1 argument - print calendar of that month
		# 2 argument - print calendar of the first input's month
		# representation and ignore second input and print
		# invalid input

	case $# in
	# $# represents the number of arguments the user inputs

		0) # if no argument
			echo "You must provide at least one month";;
	
		1) # if 1 argument
			cal -m$1 ;;
			# -m[arg1] specifies month of the current year

		2) # if 2 arguments
			cal -m$1 
			echo "$2 is not a valid month/input";;
			# only accepts first input, ignores second
			# and prints out invalid input
esac

