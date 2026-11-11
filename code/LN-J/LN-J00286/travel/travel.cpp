#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string c1,s1,c2,s2;
cin>>c1>>s1>>c2>>s2;

if(c1[0]==c2[0]&&c1[1]==c2[1]){
	cout<<"1";
	}
	else
	cout<<"0";
if(s1[1]==s2[1]&&s1[0]==s2[0]){
	cout<<"1";
}
else
cout<<"0";

char m=s1[2],n=s2[2];
if(m>n)
{m=s2[2];
n=s1[2];
	}
if(m>='A'&&m<='C'&&n>='A'&&n<='C'){
cout<<"1";

}
    else if(m>='D'&&m<='F'&&n>='D'&&n<='F')
    {cout<<"1";}
    else
    {cout<<"0";}

if(m>='A'&&m<='C'&&n>='A'&&n<='C'&&n-m==1){
	cout<<"1";}
	else if(m>='D'&&m<='F'&&n>='D'&&n<='F'&&n-m==2)
	{
		cout<<"1";}
    else
     {cout<<"0";}
return 0;
}
