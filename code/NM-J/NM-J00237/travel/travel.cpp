#include <bits/stdc++.h>
using namespace std;
int a1,a2;
string b1,b2;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travle.out","w",stdout);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a1 >> b1 >> a2 >> b2;
	int c1 = b1[0] - '0' * 10 + b1[1] - '0';
	int c2 = b2[0] - '0' * 10 + b2[1] - '0';
	int t1,t2,t3;
	t1 = t2 = t3 = 0;
	if(a1 == a2)
		printf("1"),t1 = 1;
	else
		printf("0");
	if(c1 == c2 && t1)
		printf("1"),t2 = 1;
	else
		printf("0");
	if(t1 && t2){
		if(b1[2] == 'A' || b1[2] == 'B' || b1[2] == 'C'){
			if(b2[2] == 'D' || b2[2] == 'F')
				printf("0");
			else
				printf("1"),t3 = 1;
		}
		else{
			if(b2[2] == 'D' || b2[2] == 'F')
				printf("1"),t3 = 0;
			else
				printf("0");
		}
	}
	else
		printf("0");
	if(t1 && t2 && t3){
		if(b1[2] == 'A')
			if(b2[2] == 'B')
				printf("1");
			else
				printf("0");
		else if(b1[2] == 'B')
			if(b2[2] == 'A' || b2[2] == 'C')
				printf("1");
			else
				printf("0");
		else if(b1[2] == 'C')
			if(b2[2] == 'B')
				printf("1");
			else
				printf("0");
		else if(b1[2] == 'D')
			if(b2[2] == 'F')
				printf("1");
			else
				printf("0");
		else
			if(b2[2] == 'D')
				printf("1");
			else
				printf("0");
	}
	else
		printf("0");
	/*
	t1 20 min .-.
	是否我该在这里留下洛谷uid?.
	*/
}
