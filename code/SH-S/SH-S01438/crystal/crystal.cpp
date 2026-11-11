#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],s[500005],ans,p;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	p=1;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		while(m<(ll)(i-p)*a[i]-(s[i-1]-s[p-1])) p++;
		ans=max(ans,i-p+1);
	}
	cout<<ans;
	return 0;
}
