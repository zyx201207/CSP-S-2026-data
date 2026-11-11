#include <bits/stdc++.h>
using namespace std;
int c,t;
long long n,d,ans;
long long x[2000005];
long long dis[2000005],sum[2000005];
int checkl(long long p){
	int l=0,r=n+1,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(x[mid]>=p)r=mid;
		else l=mid+1;
	}
	return l;
}
int checkr(long long p){
	int l=0,r=n+1,mid;
	while(l<r){
		mid=(l+r+1)>>1;
		if(x[mid]<=p)l=mid;
		else r=mid-1;
	}
	return l;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		x[n+1]=0x3f3f3f3f3f3f3f3f;
		x[0]=-0x3f3f3f3f3f3f3f3f;
		ans=0;
		if(c<=10){
			for(int i=1;i<=n;i++){
				dis[i]=0;
				sum[i]=1;
				for(int j=0;j<i;j++)sum[j]=0;
				for(int j=i+1;j<=n;j++){
					int l=checkl(x[j]-d);
					if(l<i)l=i;
					dis[j]=dis[l]+1;
					sum[j]=sum[l];
					if(l<=j-2&&dis[l]==dis[l+1])sum[j]+=sum[l+1];
					if(l<=j-3&&dis[l]==dis[l+2])sum[j]+=sum[l+2];
					if(sum[j]==2)ans++;
				}
			}
		}
		else if(c<=12){
			int len=d/(x[2]-x[1]);
			if(len>=2){
				for(int i=1;i<=n;i++){
					if((n-i+1)/len>=2)ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}