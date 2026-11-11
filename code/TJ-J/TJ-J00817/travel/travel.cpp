#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in.txt","r",stdin);
freopen("travel.out.txt","w",stdout);
	char s1,s2;
	int c1,c2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2&&s1==s2+'1'-'0')
		cout<<"1"<<"0"<<"0"<<"1";
		else
		cout<<"0"<<"1"<<"1"<<"0"; 
		return 0;
} 
