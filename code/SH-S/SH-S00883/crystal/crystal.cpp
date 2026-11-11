#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],d[500010],flag,vis[210],minn=1e18;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)  cin>>a[i],minn=min(minn,a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)  d[i]=a[i+1]-a[i];
	for(int i=1;i<n-1;i++)  if(d[i]!=d[i+1])  flag=1;
	if(n<=5000){
		int maxn=0;
		for(int i=1;i<n;i++){
			int sum=0,f=0;
			for(int j=i;j<=n;j++){
				sum+=d[j]*(j-i+1);
				if(sum>m){
					maxn=max(maxn,j-i+1),f=1;
					break;
				}
			}
			if(!f)  maxn=max(maxn,n-i+1);
		}
		cout<<maxn;
	}
	else if(!flag){
		int sum=0,f=0;
		for(int i=1;i<=n;i++){
			sum+=i*d[1];
			if(sum>m){
				cout<<i;
				f=1;
				break;
			}
		}
		if(!f)  cout<<n;
	}
	else{
		for(int i=1;i<=n;i++)  a[i]-=minn;
		int maxn=0;
		for(int i=1;i<=n;i++){
			if(vis[a[i]])  continue;
			int sum=0,ans=0,f=0;
			for(int j=i;j<=n;j++){
				if(a[j]!=a[j+1])  break;
				ans++;
			}
			for(int j=i-1;j>=1;j--){
				sum+=a[i]-a[j];
				if(sum>m){
					ans+=i-j,f=1;
					break;
				}
			}
			if(!f)  ans+=i;
			maxn=max(maxn,ans),vis[a[i]]=1;
		}
		cout<<maxn;
	}
	return 0;
}
