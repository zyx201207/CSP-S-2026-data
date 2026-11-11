#include<bits/stdc++.h>
using namespace std;
int main(){
    int c1,s1,c2,s2,A=1,B=2,C=3,D=4,E=5,F=6; 
	freopen("travel.in","r",stdin);
	cin>>c1>>s1>>c2>>s2;
    if(c1!=c2) 
	cout<<0;
	else
    cout<<1;
	  if(s1-s2<=6||s2-s1<=6) 
   cout<<1;
   else
   cout<<0;
   if(s1+s2>7<9||s1+s2>10)
   cout<<1;
   else
   cout<<0;
   if(s1-s2<2||s2-s1<2)
   cout<<1;
   else
   cout<<0;
freopen("travel.out","w",stdout);
	return 0;
} 
