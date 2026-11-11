#include<bits/stdc++.h>//100 
using namespace std;
#define ll long long
ll i,j;
string c1,s1,c2,s2;
bool ppp=true;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else{
		bool pq=true;
		cout<<1;
		ll q1=s1[0]+s1[1];
		ll q2=s2[0]+s2[1];
		if(q1==q2)cout<<1;
		else cout<<0,pq=false;
		if(s1[2]>='A'&&s1[2]<='C'){
			if(s2[2]>='A'&&s2[2]<='C'&&pq){
				cout<<1;
			}
			else cout<<0,ppp=false;
		}
		else{
			if(s2[2]=='D'||s2[2]=='F'){
				cout<<1;
			}
			else cout<<0,ppp=false;
		}
		if(ppp){
			if(s1[2]=='A'&&s2[2]=='B'){
				cout<<1;
				return 0;
			}
			if(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C')){
				cout<<1;
				return 0;
			}
			if(s1[2]=='C'&&s2[2]=='B'){
				cout<<1;
				return 0;
			}
			if(s1[2]=='D'&&s2[2]=='F'){
				cout<<1;
				return 0;
			}
			if(s1[2]=='F'&&s2[2]=='D'){
				cout<<1;
				return 0;
			}
		}
		cout<<0; 
	}
	return 0;
}

