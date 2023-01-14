//This library is used to compare enumerated values in an unbiased RockPaperScissors-esque system
//The enumerated values should be based on a graph aranged in such a way slicing it across from one option cleanly divided it into groups of options that win and lose against the option chosen
//The afformentioned graph is possible for any unbiased RPS-like system

//macro define 'RPSoptions' before including file
#ifndef RPSoptions
#define RPSoptions 7 //this logic was originally made for a system with 7 options, so using it as the default felt right
#endif

//I think I named this as an abreviation of victim limit, meaning the amount of options one option can beat
#define vicLim (RPSoptions / 2 - (RPSoptions / 2) % 1)

//named for the graph idea mentioned earlier, this changes the enumerated value of b as though a was 0
#define rotate(a,b) (b + (RPSoptions - a)) % RPSoptions

//Compares 2 enumerated options for RPS-like system
int RPSComp(int home,int away){
	if(home==away) return 0;//draw
	
	int check = rotate(home,away)-vicLim;

	//1 win
	//-1 lose
	return 2*(check<=0)-1;
}

//Verbose version for dealing with even options. incase that's ever somehow needed
int RPSCompV(int home, int away){
	return (RPSComp(home,away)-RPSComp(away,home))/2;
	//yes, this function does try it both ways as though it were an odd N system
	//and then if the outcomes contradict it determines a draw
}


//Bias checking functions, mainly for testing purposes
//if the answer comes up 0 then everything's working correctly

//Bias check for an odd N system
//trying this for an even N system should give a none-zero answer
int* biasCheck(){
	int n=RPSoptions,m;
	int* balance = calloc(RPSoptions+1,8);
	while(n--){
		m=RPSoptions;
		while(m--){
			balance[n]+=RPSComp(n,m);
		}
	}
	return balance;
}

//Bias check for even N systems
//should always come out as 0
int* biasCheckV(){
	int n=RPSoptions,m;
	int* balance = calloc(RPSoptions+1,8);
	while(n--){
		m=RPSoptions;
		while(m--){
			balance[n]+=RPSCompV(n,m);
		}
	}
	return balance;
}
