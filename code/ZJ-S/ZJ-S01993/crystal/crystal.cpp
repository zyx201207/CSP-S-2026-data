#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],s[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int ans=0;
	for(int i=1,j=1;i<=n;i++){
		while(a[i]*(i-j+1)-(s[i]-s[j-1])>m)j++;
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}

