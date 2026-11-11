#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
//const int N=;
int c1,c2,p1=0,p2=0;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		for(int i=0;i<=1;i++){
			p1=p1*10+(s1[i]-'0');
			p2=p2*10+(s2[i]-'0');
		}
		if(p1==p2){
			cout<<1;
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'
			&&s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
				cout<<1;
				if(s1[2]=='A'&&s2[2]=='B'||
				s1[2]=='B'&&s2[2]=='A'){
					cout<<1;
				}
				else if(s1[2]=='B'&&s2[2]=='C'||
				s1[2]=='C'&&s2[2]=='B'){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else if(s1[2]=='D'||s1[2]=='F'&&
				s2[2]=='D'||s2[2]=='F'){
				cout<<"11";
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
