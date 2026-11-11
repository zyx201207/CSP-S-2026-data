#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	string c1,s1,c2,s2,h1,h2;
	char l1,l2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		h1=s1.substr(0,2);
		h2=s2.substr(0,2);
		if(h1==h2){
			cout<<1;
			l1=s1[2],l2=s2[2];
			if((l1<='C'&&l2<='C')||(l1>'C'&&l2>'C')){
				cout<<1;
				if(l1>l2){
					swap(l1,l2);
				}
				if((l1=='A'&&l2=='B')||(l1=='B'&&l2=='C')||(l1=='D'&&l2=='E')){
					cout<<1;
				}
				else{
					cout<<0;
				}
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