#include<bits/stdc++.h>
using namespace std;
int a,b;
string c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>a>>c>>b>>d;
	if(a!=b){
		cout<<"0000";
		return 0;
	}else cout<<1;
	if(c[0]!=d[0]||c[1]!=d[1]){
		cout<<"000";
		return 0;
	}else cout<<1;
	if(c[2]=='A'||c[2]=='B'||c[2]=='C'){
		if(d[2]=='D'||d[2]=='F'){
			cout<<"00";
			return 0;
		}else{
			if(c[2]==d[2]+1||c[2]==d[2]-1) cout<<"11";
			else cout<<"10";
		}
		return 0;
	}
	if(c[2]=='D'||c[2]=='F'){
		if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
			cout<<"00";
			return 0;
		}else{
			if(c[2]==d[2]+1||c[2]==d[2]-1) cout<<"11";
			else cout<<"10";
		}
	}
	return 0;
}
