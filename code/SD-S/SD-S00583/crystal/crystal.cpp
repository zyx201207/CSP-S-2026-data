#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],q[500005];int ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long sum=0,slen=0;
	for(int i=1,l=1,r=0;i<=n;i++){
		if(a[i]==a[i-1]){
			q[++r]=i;
			ans=max(ans,r-l+1);//cout<<r-l+1<<'\n';
			continue;
		}
		slen=r-l+1;
		sum=sum+slen*(a[i]-a[i-1]);
		while(l<=r&&sum>m){
			sum=sum-(a[i]-a[q[l]]);
			l++;slen--;
		}
		q[++r]=i;
		ans=max(ans,r-l+1);//cout<<r-l+1<<'\n';
	}
	cout<<ans;
	return 0;
}
