#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	int c1,s1,c2,s2;
	cin>>c1>>c2;
	cin>>s1,s2;
	if(c1%10==c2%10)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(c1/10==c2/10)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(s1%10==s2%10)
	{
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(s1/10%10==s2/10%10){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(s1/100==s2/100){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}