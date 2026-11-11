#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const int N=1e6+10,M=1e3+10,MOD=1e9+7;
bool p1(char x,char y){
	if(x>y) swap(x,y);
	if(x=='A'&&y=='B'||x=='A'&&y=='C'||x=='B'&&y=='C'||x=='D'&&y=='F') return true;
	return false;
}
bool p2(char x,char y){
	if(x>y) swap(x,y);
	if(x=='A'&&y=='B'||x=='B'&&y=='C'||x=='D'&&y=='F') return true;
	return false;
}
int main(){
	fastio;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ll a,b,c,d;
	char s,x,y;
	cin>>a>>s>>c>>x>>b>>s>>d>>y;
	if(a==b) cout<<1;
	else cout<<0;
	if(a==b&&c==d) cout<<1;
	else cout<<0;
	if(a==b&&c==d&&p1(x,y)) cout<<1;
	else cout<<0;
	if(a==b&&c==d&&p2(x,y)) cout<<1;
	else cout<<0; 
	return 0;
}
