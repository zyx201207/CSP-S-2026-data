#include<bits/stdc++.h>
using namespace std;
#define int long long
string a,b,c,d;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(b[0]!=d[0]||b[1]!=d[1]){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	if(b[2]=='F'){
		if(d[2]=='D'){
			cout<<"11";
			return 0;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	if(b[2]=='D'){
		if(d[2]=='F'){
			cout<<"11";
			return 0;
		}
		else{
			cout<<"00";
			return 0;
		}		
	}
	if(d[2]=='F'||d[2]=='D'){
		cout<<"00";
		return 0;
	}
	cout<<"1";
	if(b[2]=='C'){
		if(d[2]=='B')cout<<"1";
		else cout<<"0";		
	}else if(b[2]=='B'){
		if(d[2]=='C'||d[2]=='A')cout<<"1";
		else cout<<"0";
	}else{
		if(d[2]=='B')cout<<"1";
		else cout<<"0";
	} 
	return 0;
}
