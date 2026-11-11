#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
long long a[5];
int main(){
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		a[1]=1;
	}
	else
	{
		a[1]=0;
		cout<<"0000";
		return 0;
		
	}
	if((s1[0]==s2[0])&&(s1[1]==s2[1]))
	{
		a[2]=1;
	}
	else
	{
		a[2]=0;
		cout<<"1000";
		return 0;
	}
	char x,y;
	for(int i=0;i<=3;i++){
		if(s1[i]=='A'||s1[i]=='B'||s1[i]=='C'||s1[i]=='D'||s1[i]=='E')x=s1[i];
		if(s1[i]=='A'||s1[i]=='B'||s1[i]=='C'||s1[i]=='D'||s1[i]=='E')y=s2[i];
	}
	int x1,x2;
	if(x=='A')x1=1;
	if(x=='B')x1=2;
	if(x=='C')x1=3;
	if(x=='D')x1=4;
	if(x=='E')x1=5;
	if(y=='A')x2=1;
	if(y=='B')x2=2;
	if(y=='C')x2=3;
	if(y=='D')x2=4;
	if(y=='E')x2=5;

	if(x1+x2<=4||x1+x2==9)
	{
		a[3]=1;
		if(x1+x2==3||(x1==2 && x2==3)||x1+x2==9||(x1==3 && x2==2)){
			a[4]=1;
		}
	}
	else
	{
		a[3]=0;
		a[4]=0;
		
	}
	for(int i=1;i<=4;i++)
	{
		cout<<a[i];
	}
	return 0;
} 
