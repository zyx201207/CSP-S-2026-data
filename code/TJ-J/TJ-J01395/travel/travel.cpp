#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	if(c1!=c2){
		cout<<0;
	}
	if(s1[1]==s2[1]){
		cout<<1;
	}
	if(s1[1]!=s2[1]){
		cout<<0;
	}
	char ch1,ch2,maxn;
	ch1=s1[2];
	ch2=s2[2];
	
	if(ch1>ch2){
		maxn=ch1;
		ch1=ch2;
	}
	if(ch2>ch1){
		maxn=ch2;
	}
	ch2=maxn-ch1;
	if(ch2<=2){
		cout<<1;
		if(ch2==1){
			cout<<1;
			return 0;
		}
		if(maxn==70){
			cout<<1;
			return 0;
		}
	}
	if(ch2>2){
		cout<<0;
	}
	if(ch2==2){
		cout<<0;
	}
	
	return 0;
}
