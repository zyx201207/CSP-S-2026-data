#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a,l,ans;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a>>c;
		l+=a;
		for(ll j=1;j<=a;j++)s+=c;
	}
	ll l2=ceil(l/2.0);
	for(ll i=0;i<l2;i++)
		if(s[i]!=s[l-i-1])ans++;
	cout<<ans;
	return 0;
}
//暴力68 打不动了 
//建议升黑 

