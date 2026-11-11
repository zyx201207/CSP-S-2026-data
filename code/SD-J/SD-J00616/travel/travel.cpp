#include<bits/stdc++.h>
#define int long long
using namespace std; 
struct node{
	int a;
	string s;
};
node a,b;
bool check(char c1,char c2){
	if(c1=='A'||c1=='B'||c1=='C'){
		if(c2=='A'||c2=='B'||c2=='C'){
			return 1;
		}
	}
	if(c1=='D'||c1=='F'){
		if(c2=='D'||c2=='F'){
			return 1;
		}
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a.a>>a.s>>b.a>>b.s;
	if(a.a==b.a){
		if(a.s[0]==b.s[0]&&a.s[1]==b.s[1]){
			if(check(a.s[2],b.s[2])){
				if(a.s[2]+1==b.s[2]||a.s[2]-1==b.s[2]){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
}
