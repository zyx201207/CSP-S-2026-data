#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
using ll=long long;
const int N=2e5+10;
struct Node{
	ll a;
	char c;
}x[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	fast;
	int n;
	cin>>n;
	ll g=0;
	for(int i=1;i<=n;i++){
		cin>>x[i].a>>x[i].c;
		if(g==0) g=x[i].a;
		else g=__gcd(g,x[i].a);
	}
	ll cnt=0;
	string s;
	for(int i=1;i<=n;i++){
		x[i].a/=g;
		cnt+=x[i].a;
		int k=x[i].a;
		while(k--){
			s+=x[i].c;
		}
	}
	ll ans=0;
	for(int i=0;i<cnt/2;i++){
		if(s[i]!=s[s.size()-i-1]) ans++;
	}
	cout<<ans*g;
	return 0;
}