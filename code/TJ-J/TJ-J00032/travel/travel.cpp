#include<bits/stdc++.h>
using namespace std;
int a[500005]; 
int main(){
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
	string c1,s1;
	string c2,s2;
	cin>>c1>>s1>>c2>>s2;
		if(c1==c2)	cout<<1111;
		if(c1==c2||s1-s2<=5)	cout<<1110;
		if(c1==c2||s1-s2<=3)	cout<<1100;
		if(c1==c2||s1-s2<=3&&s1-s2==1)	cout<<0000;
		
	
	
	




	return 0;
}

