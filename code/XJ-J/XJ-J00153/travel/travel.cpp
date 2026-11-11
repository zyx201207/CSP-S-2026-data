#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool q1=c1[0]==c2[0]&&c1[1]==c2[1];
	bool q2=q1&&s1[0]==s2[0]&&s1[1]==s2[1];
	bool q3=0;
	if(q2){
		char jud[8][2]={
		{'A','B'},
		{'A','C'},
		{'B','A'},
		{'B','C'},
		{'C','A'},
		{'C','B'},
		{'D','F'},
		{'F','D'}};
		for(int ji=0;ji<6;ji++){
			if(jud[ji][0]==s1[2]&&jud[ji][1]==s2[2])
			q3=1;
		}
	}
	bool q4=0;
	if(q3){
		char jud[6][2]={
		{'A','B'},
		{'B','A'},
		{'B','C'},
		{'C','B'},
		{'D','F'},
		{'F','D'}
		};
		for(int ji=0;ji<6;ji++){
			if(jud[ji][0]==s1[2]&&jud[ji][1]==s2[2])
			q4=1;
		}
	}
	cout<<q1<<q2<<q3<<q4;
	return 0;
}
