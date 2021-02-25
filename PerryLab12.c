#include <stdio.h>
#define SIZE 7

//function prototypes
int getGrade(unsigned int gradeNumber);
void bubbleSort(unsigned int grades[]);
void displayLetter(float grade);

// function  main begins program execution
int main(void)
{
	unsigned int i;
	unsigned int grades[SIZE];
	unsigned int gradeTotal = 0;
	float gradeAverage;
	//for loop that calls a function to get valid grades and assign them to the array
	for(i = 0; i < 6; i++){
		grades[i] = getGrade(i + 1);
	}
	
	//pass the array to a function that sorts it from smallest to largest
	bubbleSort(grades);
	
	//print heading
	puts("\nSorted grades:\n");
	
	for(i = 0; i < 6; i++){
		printf("%3u", grades[i]);
		displayLetter((float)grades[i]);
		puts("");
		gradeTotal += grades[i];
	}
	
	gradeAverage = (float)gradeTotal / 6;
	printf("\nGrade average: %.1f%%", gradeAverage);
	displayLetter(gradeAverage);
	puts("");
} //end function main

int getGrade(unsigned int gradeNumber){
	int inputGrade;
	do{
		printf("Enter grade %u:", gradeNumber);
		scanf("%u", &inputGrade);
	}while(inputGrade < 0 || inputGrade > 100); //repeats printf statement if any inputted grades are either higher than 100 or lower than 0
	return inputGrade;
}

void bubbleSort(unsigned int grades[]){
	unsigned int pass;
	size_t j;
	unsigned int hold;
	
	//loop that will sort the array elements in ascending order
	for(pass = 1; pass < 6; pass++){
		for(j = 0; j < 6; j++){
			if(grades[j] > grades[j + 1]){
				hold = grades[j];
				grades[j] = grades[j + 1];
				grades[j + 1] = hold;
			}
		}
	}
}

void displayLetter(float grade) {
	if(grade >= 90 || grade == 100){
		printf("%s", " - A");
	} else if (grade >= 80){
		printf("%s", " - B");
	} else if (grade >= 70){
		printf("%s"," - C");
	} else if(grade >= 60){
		printf("%s", " - D");
	} else {
		printf("%s"," - F");
	}
}
