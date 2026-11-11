#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long pre[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	long long ans=0;
	for(long long i=1,j=1;i<=n;i++){
		while((i-j+1)*a[i]-(pre[i]-pre[j-1])>m)j++;
		ans=max(ans,i-j+1);
	}
	cout<<ans;
}
