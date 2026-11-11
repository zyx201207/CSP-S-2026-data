#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll> pll;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	string c1,s1,c2,s2;cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		if(s1.substr(0,2)==s2.substr(0,2)){
			bool flag=false;
			char a=s1[s1.size()-1],b=s2[s2.size()-1];
			if('A'<=a&&a<='C'){
				if('A'<=b&&b<='C')flag=true;
			}else{
				if(b=='D'||b=='F')flag=true; 
			}
			if(flag){
				if(a=='A'&&b=='B'){
					cout<<"1111";
					return 0;
				}
				if(a=='B'&&(b=='A'||b=='C')){
					cout<<"1111";
					return 0;
				}
				if(a=='C'&&b=='B'){
					cout<<"1111";
					return 0;
				}
				if(a=='D'&&b=='F'){
					cout<<"1111";
					return 0;
				}
				if(a=='F'&&b=='D'){
					cout<<"1111";
					return 0;
				}
				cout<<"1110"; 
			}else{
				cout<<"1100";
				return 0;
			}
		}else{
			cout<<"1000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
