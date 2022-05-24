Requirements:
1.	Declare a University structure array name university[10]. (5 points)
2.	Store the database above to the structure array university[10]. This university[] array, MUST NOT be used as global variable.
3.	Implement a function that will display all information of a university. 
4.	Implement a function that will display the top nth university then display the result.
5.	Implement a function that will display all universities of a specific state then display the result. 
6.	Implement a function that will display the university with highest and lowest tuition then display the result. 
7.	Implement a function that sorts the universities bases on the tuition from highest to lowest then display the sorted list.
8.	Call all the above functions by using the code below in your main function for testing purpose: (5 points) which x is your choice of the parameters that you have used for the above requirements.
printInfo(struct University u);
printTopUniversity(x, n); //with n is your choice
printStateofUniversity(x, c); //wich c is your choice
printMinMaxTuitionUniversity(x);
printSortedUniversity(x);
Optional Requirements:
1.	A function that calculate average tuition of the 10 universities using  recursion manner.
2.	Implement a function that will sort the rank of the universities from low to high using a O(n*log(n)) complexity.
