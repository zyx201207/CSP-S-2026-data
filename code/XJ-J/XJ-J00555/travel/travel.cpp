#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,c1,c2;
	int ch1,ch2,x3=0,x4=0,a1,a2;
	cin>>ch1>>s1>>ch2>>s2;
	for(int i=1;i<=3;i++){
		a1=s1[0]+s1[1];
		c1=s1[2];
	}
	for(int i=1;i<=3;i++){
		a2=s2[0]+s2[1];
		c2=s2[2];
	}
	if(ch1!=ch2){
		cout<<"0000";
		return 0;
	}
	else if(a1!=a2){
		cout<<"1000";
		return 0;
	}
	else if((c1=="A"||c1=="B"||c1=="C")&&(c2=="A"||c2=="B"||c2=="C"))x3=1;
	else if((c1=="D"||c1=="E")&&(c2=="D"||c2=="E"))x3=1;
	if((c1=="A"&&c2=="B")||(c1=="B"&&c2=="C")||(c1=="D"&&c2=="E")||(c2=="A"&&c1=="B")||(c2=="B"&&c2=="C")||(c2=="D"&&c1=="E")){
		x4=1;
	}

	cout<<"11"<<x3<<x4;
}