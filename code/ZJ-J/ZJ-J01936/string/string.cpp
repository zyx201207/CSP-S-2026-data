#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll n,a[200010],ans;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i]>>c[i];
	for(ll l=1,r=n;l<=r;){
		if(c[l]!=c[r])ans+=min(a[l],a[r]);
		if(a[l]==a[r])l++,r--;
		else if(a[l]>a[r])a[l]-=a[r--];
		else a[r]-=a[l++];
	}
	cout<<ans;
	return 0;
}
