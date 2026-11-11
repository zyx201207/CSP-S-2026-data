/*#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal3.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=0;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		if(sum[i]+m>=a[i]*i)
			ans=i;
	}
	cout<<ans;
*/
#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		int sum=0;
		for(int i=1;i<=mid;i++)
			sum+=(a[mid]-a[i]);
		if(sum<=m)
			l=mid;
		else
			r=mid-1;
	}
	cout<<l;
	return 0;
}
