#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d,s=0;
	char x,y;
	cin>>a>>b>>x>>c>>d>>y;
	if(a==c){
		cout<<1;	
	}
	else 
	{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(b==d){
		cout<<1;
		s=1;
	}
	else cout<<0;
	if(b==d&&x=='D'&&y=='F')cout<<1;
	else if(b==d&&x=='F'&&y=='D')cout<<1;
	else if(b==d&&x=='A'&&y=='B')cout<<1;
	else if(b==d&&x=='B'&&y=='A')cout<<1;
	else if(b==d&&x=='B'&&y=='C')cout<<1;
	else if(b==d&&x=='C'&&y=='B')cout<<1;
	else if(b==d&&x=='C'&&y=='A')cout<<1;
	else if(b==d&&x=='A'&&y=='C')cout<<1;
	else cout<<0;
	if(s){
		if(x=='D'&&y=='F')cout<<1;
		else if(x=='F'&&y=='D')cout<<1;
		else if(x=='A'&&y=='B')cout<<1;
		else if(x=='B'&&y=='A')cout<<1;
		else if(x=='B'&&y=='C')cout<<1;
		else if(x=='C'&&y=='B')cout<<1;
		else cout<<0;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
