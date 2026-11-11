#include<bits/stdc++.h>
using namespace std;
int c1,c2;
int a,b;
char ch1,ch2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>a>>ch1>>c2>>b>>ch2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(a!=b){
		cout<<"1000";
		return 0;
	}
	if(a==b){
		cout<<"11";
		if((ch1=='D'||ch1=='F')&&(ch2=='D'||ch2=='F')){
			cout<<"11";
			return 0;
		}
		if((ch1=='A'||ch1=='B'||ch1=='C')&&(ch2=='A'||ch2=='B'||ch2=='C')){
			cout<<"1";
			if((ch1=='A'&&ch2=='B')||(ch1=='B'&&ch2=='C')){
				cout<<"1";
			}
			else{
				cout<<"0";
			}
			return 0;
		}
		else{
			cout<<"00";
		}
	}
	return 0;
}

