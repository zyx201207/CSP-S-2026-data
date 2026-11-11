#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,maxx=INT_MIN,a,b,c,d;
const int N=2e5+10;
string s[N];
bool two(string n){
	bool f=true;
	ll x=0;
	for(int i=0;i<n.size();i++) x=x*10+n[i]-'0';
	while(f&&x!=1){
		ll y=x/2;
		if(y*2!=x) f=false;
		else x/=2;
	}
	if(!f) return 1;
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		ll x=s[i].size();
		maxx=max(maxx,x);
	}
	for(int i=1;i<=n;i++){
		ll x=s[i].size();
		while(x!=maxx){
			s[i]='0'+s[i];
			x++;
		}
	}
	sort(s+1,s+n+1);
	ll i=n;
	while(!two(s[i])){
		--i;
		++m;
	}
	while(s[n-m+1][0]=='0') s[n-m+1].erase(0,1);
	cout<<s[n-m+1]<<'\n';
	return 0;
}
