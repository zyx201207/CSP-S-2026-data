#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long n,m;
long long sum,ans=1,cnt=1,u=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+1+n);
	sum=a[1];
	for(int i=2;i<=n;i++){
		sum+=a[i];
		cnt++;
		while(cnt*a[i]-sum>m){
			cnt--;
			sum-=a[u];
			u++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<"\n";
	return 0;
}
