#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN=2e5+99;
ll a[MAXN];
ll s[MAXN];
char c[MAXN];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin>>n;
	ll tot=0;
	string s1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s1.push_back(c[i]);
		}
	}
	string s2=s1;
	ll ans=0;
	reverse(s1.begin(),s1.end());
	for(int i=0;i<s1.size();i++){
		if(s1[i]!=s2[i]){
			ans++;
		}
	}
	ans/=2;
	clog<<ans<<endl;
	return 0;
} 
