#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=2e5+10;
string s;
ll n,pos[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		ull y;
		char x;
		cin>>y>>x;
		s[i]=x;
		pos[i]=y;
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(s[i]!=s[n+1-i]){
			s[i]=s[n+1-i];
			ans+=pos[i];
		}
	}
	cout<<ans<<'\n';
}
