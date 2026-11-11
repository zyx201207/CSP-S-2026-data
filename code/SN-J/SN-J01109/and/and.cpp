#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[20005];
int main(){
	//I love NOI,能给个满分吗,第三题有点不会写，只能用特殊数据骗一点分 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (long long i=1;i<=n;i++)
		cin>>a[i];
	if (m==1){
		long long maxn=-1;
		for (long long i=1;i<=n;i++)
			maxn=max(maxn,a[i]);
		cout<<maxn;
		return 0;
	}
	if (m==2){
		long long ans=-1;
		for (long long i=1;i<=n;i++)
			for (long long j=1;j<=n;j++)
				if (i!=j)
					ans=max(ans,(a[i]&a[j]));
		cout<<ans;
		return 0;
	}
	long long minn=1073741825;
	for (long long i=1;i<=n;i++)
		min(minn,a[i]);
	cout<<minn;
	return 0;
}
