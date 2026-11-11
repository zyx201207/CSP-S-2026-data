#include<bits/stdc++.h>
using namespace std;
bool c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	std::ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
		return 0;
	}
	if((b[0]==d[0])&&(b[1]==d[1])){
		if(((b[2]=='F'||b[2]=='D')&&(d[2]=='F'||d[2]=='D'))||((b[2]=='C'||b[2]=='B'||b[2]=='A')&&(d[2]=='C'||d[2]=='B'||d[2]=='A'))){
			if((b[2]=='F'||b[2]=='D')&&(d[2]=='F'||d[2]=='D')){
				cout<<"1111";
			}else if(b[2]+1==d[2]||d[2]+1==b[2]){
				cout<<"1111";
			}else{
				cout<<"1110";
			}
		}else{
			cout<<"1100";
		}
	}else{
		cout<<"1000";
		return 0;
	}
	return 0;
} 
