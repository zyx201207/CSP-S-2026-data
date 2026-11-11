#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int N=5e3+5;
const int INF=0x3f3f3f3f;
int c,t,ans;
ll  n,dis[N][N],cnt[N][N];
ll a[N],d,l[N],r[N];
int find(int id) {
	int l=id,r=n,mid,ret;
	while(l<=r) {
		mid=(l+r)>>1;
		if(a[mid]-a[id]<=d) ret=mid,l=mid+1;
		else r=mid-1;
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		cin>>n>>d;
		ans=0;
		for(int i=0; i<=n; i++)
			for(int j=0; j<=n; j++) dis[i][j]=INF,cnt[i][j]=0;
		for(int i=1; i<=n; i++) dis[i][i]=0,l[i]=r[i]=1;
		for(int i=1; i<=n; i++) cin>>a[i];
		for(int len=2; len<=n; len++)
			for(int l=n+1-len; l>=1; l--) {
				int maxr=find(l),r=l+len-1;
				if(maxr>=r) dis[l][r]=1,cnt[l][r]=1;
				else {
					for(int j1=maxr; j1>l; j1--) {
						int val=dis[j1][r]+1;
						if(cnt[l][r]>=3) break;
						if(dis[l][r]>val) dis[l][r]=val,cnt[l][r]=cnt[j1][r];
						else if(dis[l][r]==val) cnt[l][r]+=cnt[j1][r];
						else break;
					}
				}
			}
		for(int i=1; i<=n; i++)
			for(int j=i+1; j<=n; j++)
				if(cnt[i][j]==2) ans=ans+1;
		cout<<ans<<endl;
	}
	return 0;
}
