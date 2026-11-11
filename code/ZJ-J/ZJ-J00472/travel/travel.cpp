#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
		return 0;
	}
	if(b[0]!=d[0] || b[1]!=d[1]){
		cout<<"1000";
		return 0;
	}
	if(b[2]!='D' && b[2]!='F' && d[2]!='D' && d[2]!='F'){
		if(b[2]=='B' || d[2]=='B') cout<<"1111";
		else cout<<"1110";
	}
	else if((b[2]=='F' && d[2]=='D') || (b[2]=='D' && d[2]=='F')) cout<<"1111";
	else cout<<"1100";
	return 0;
}
