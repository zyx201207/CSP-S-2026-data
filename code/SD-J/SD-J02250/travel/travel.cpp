#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
int a,b;
string s,d;
cin>>a>>s>>b>>d;
if(a!=b){
 	cout<<"0000";
 	return 0;
 }
if(s[0]!=d[0]||s[1]!=d[1]){
     cout<<"1000";
	 return 0;	
}
int y,u;
if(s[2]=='F'||s[2]=='D')
{
	y=1;
}
if(d[2]=='F'||d[2]=='D')
{
	u=1;
}
if(s[2]=='A'||s[2]=='B'||s[2]=='C')
{
	y=0;
}
if(d[2]=='A'||d[2]=='B'||d[2]=='C')
{
	u=0;
}
if(y!=u)
{
	cout<<"1100";
	return 0;
}
if(s[2]-1!=d[2]&&s[2]+1!=d[2])
{
	cout<<"1110";
	return 0;
}
cout<<"1111";
	return 0;
} 
