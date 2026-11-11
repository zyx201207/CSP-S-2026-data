#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+10;
string a,b,c,d;
ll f(char ch){
	if(ch=='A') return 1;
	if(ch=='B') return 2;
	if(ch=='C') return 3;
	if(ch=='D') return 101;
	if(ch=='F') return 102;
	return -1;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	ll x=f(b[2]),y=f(d[2]);
	if(x>y) swap(x,y);
	if(a!=c) cout<<"0000";
	else if(b[0]!=d[0]||b[1]!=d[1]) cout<<"1000";
	else if(y-x>10) cout<<"1100";
	else if(x+1!=y) cout<<"1110";
	else cout<<"1111";
	return 0;
}
