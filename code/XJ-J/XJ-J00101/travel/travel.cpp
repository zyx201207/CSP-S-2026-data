#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<=17;i++) 
	{
			if(c1==c2)
			{
				cout<<"1";
			}
			else
			{
				cout<<"0";
			}
	}
	int p1,p2;
	if(p1==p2)
	{
		cout<<"1";
	}
	else 
	{
		cout<<"0";
	}
	string h1,h2;
	string A,B,C,D,F;
	for(int j=0;j<=18;j++){
		if(h1==h2){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
		for(int n=0;n<=3;n++){
			if(h==A||B||C){
				cout<<"1";
				else if(h==D||F)
			}
			else{
				cout<<"0";
			}
		}
	}
	string s1=p1&&h1,s2=p2&&h2;
	cout<<c1<<" "<<s1<<" "<<c2<<" "<<s2;
	return 0;
} 
