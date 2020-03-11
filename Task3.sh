#!/bin/bash

#Task3
#Muptiple Choice of 5Q and 2 options as answer
#Record file is created each time its ran and stores the answer 
#And marks of the student.

#INSTRUCTIONS: enter the student name and answer the following questions. scores are shown after answering five questions. score and details are recording in a temp file

	#Ask the user to input the name
	echo "Enter student's name: "
	#read function is used
	read name

	#Initialize var time and function date was used
	time=$(date +"%T")

	echo "Time Started: $time"
	
	#Pass student details to file
	echo "Student">> records.txt
	echo "Name: $name">> records.txt
	echo "Start time: $time">> records.txt

	#Initialize the score
	score=0
	
	#Q1
	echo -e "\n====="
	echo -e "Q1 \n"
	echo "What is 9 x 9?"
	echo -e "a. 18 \nb. 81"
		read Q1ans

		#test if the answer is correct
		if test "$Q1ans" = "b"
		then 
			#add 20 to score
			let "score = $score + 20"
			echo "Q1 was correct" >> records.txt
		else
			echo "Q1 was incorrect" >> records.txt
		fi
	echo -e "\n====="

	echo -e "Q2 \n"
 	echo "What is 8 x 8?"
 	echo -e "a. 64 \nb. 46"
 		read Q2ans
 		if test "$Q2ans" = "a"
 		then    
 			let "score = $score +20"
 			echo "Q2 was correct" >> records.txt
 		else    
 			echo "Q2 was incorrect" >> records.txt
 		 fi      
	echo -e "\n====="

	echo -e "Q3 \n"
	echo "What is 7 x 7?"
	echo -e "a. 49 \nb. 94"
		read Q3ans
		if test "$Q3ans" = "a"
		then
			let "score = $score +20"
			echo "Q3 was correct" >> records.txt
		else
			echo "Q3 was incorrect" >> records.txt
		fi
	echo -e "\n====="

        echo -e "Q4 \n"
        echo "What is 6 x 6?"
        echo -e "a. 63 \nb. 36"
                read Q4ans
                if test "$Q4ans" = "b"
                then
                        let "score = $score +20"
                        echo "Q3 was correct" >> records.txt
                else
                        echo "Q3 was incorrect" >> records.txt
                fi
        echo -e "\n====="
	
	echo -e "Q5 \n"
        echo "What is 5 x 5?"
        echo -e "a. 25 \nb. 52"
                read Q5ans
                if test "$Q5ans" = "a"
                then
                        let "score = $score +20"
                        echo "Q3 was correct" >> records.txt
                else
                        echo "Q3 was incorrect" >> records.txt
                fi
        echo -e "\n====="

echo "Thank you for answering, score is $score /100. Records are  updated in file"
echo "total mark: $score" >> temp


