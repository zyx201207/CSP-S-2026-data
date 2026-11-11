#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else cout<<0;
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1;
	else cout<<0;
	bool f=0;
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
		if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
				cout<<1;
				f=1;
			}
			else cout<<0;
		}else{
			if(s1[2]=='D'||s1[2]=='F'){
				if(s2[2]=='D'||s2[2]=='F'){
					cout<<1;
					f=1;
				}else{
					cout<<0;
				}
			}
		}
	}else{
		cout<<0;
	}
	if(f){
		if(abs(s1[2]-s2[2])==1) cout<<1;
		else cout<<0;
	}else{
		cout<<0;
	}
	return 0;
}
