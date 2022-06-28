//macro define 'options' before including file

#ifndef options
#define options 7
#endif

#define vicLim (options/2 - (options/2)%1)

#define rotate(a,b) (b+(options-a))%options

int RPSComp(int home,int away){
	if(home==away) return 0;//draw
	
	int check = rotate(home,away)-vicLim;

	//1 win
	//-1 lose
	return 2*(check<=0)-1;
}

//Verbose version for dealing with even options
int RPSCompV(int home, int away){
	return (RPSComp(home,away)-RPSComp(away,home))/2;

}

int* biasCheck(){
	int n=options,m=options;
	int* balance = calloc(options+1,8);
	while(n--){
		m=options;
		while(m--){
			balance[n]+=RPSComp(n,m);
		}
	}
	return balance;
}

int* biasCheckV(){
	int n=options,m=options;
	int* balance = calloc(options+1,8);
	while(n--){
		m=options;
		while(m--){
			balance[n]+=RPSCompV(n,m);
		}
	}
	return balance;
}
