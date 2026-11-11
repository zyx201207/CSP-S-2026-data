#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll a[200007];
char c[200007];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ll sum=0;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for (int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	int ans=0;
	string y=s;
	reverse(s.begin(),s.end());
	n=y.length()+1;
	for (int i=0;i<n/2;i++){
		ans+=(y[i]!=s[i]);
	}
	cout<<ans;
	return 0;
}
