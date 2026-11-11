#include<bits/stdc++.h>
using namespace std;

#define ll long long 

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ll a1,a2;
	string b1,b2;
	cin>>a1>>b1>>a2>>b2;
	
	ll p1,p2,l1,l2;
	p1=(b1[0]-'0')*10+(b1[1]-'0');
	p2=(b2[0]-'0')*10+(b2[1]-'0');
	l1=b1[2]-'A'+1;
	l2=b2[2]-'A'+1;
	if(a1==a2){
		cout<<"1";
		if(p1==p2){
			cout<<"1";
			if(l1<=3 && l2<=3 || l1>3 && l2>3){
				cout<<"1";
				if(abs(l1-l2)==1) cout<<1;
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	return 0;
}
