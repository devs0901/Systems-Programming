#Shell script which can write current time into some file continuously after 5 seconds until user interrupts

# !/bin/bash

	#set variable time
        #function date is used and format T	
	time=$(date +"%T")

		#set condition
		while true
		do
			#print the current time in text file
			echo "Current time: $now" >> sampling.txt
       			#interval is 5 seconds
		       	sleep 5

		done       

