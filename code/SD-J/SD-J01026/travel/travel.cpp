#include<bits/stdc++.h>
using namespace std;
int A[4]={0};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out ","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)A[1]=1;
	else {cout<<"0000";
			return 0;}
	int p1=s1[0]*10+s1[1];
	int p2=s2[0]*10+s2[1];
	if(p1==p2)A[2]=1;
	if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
	A[3]=1;
	A[4]=1;
	for(int i=1;i<=4;i++){
		cout<<A[i];
		return 0;
	}}
	if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')){
		A[3]=1;
		A[4]=1;}
	if((s1[3]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')){
		A[3]=1;
	}
	for(int i=1;i<=4;i++){
		cout<<A[i];
	}
	return 0;
} 
