#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define pii pair<int,int>
#define mkp(a,b) make_pair(a,b)
using namespace std;
int C,T;
namespace Subtask1{
	const int N=5105;
	int n,d,a[N],r[N],c[N],dis[N];
	void Solve(){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) r[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
		int ans=0;
		for(int s=1;s<=n;s++){
			for(int j=s-1;j<=n;j++) dis[j]=INF,c[j]=0;
			dis[s]=0;c[s]=1;int k=s;c[s+1]--;
			int l=s;
			for(int j=s;j<=n;j++){
				c[j]+=c[j-1];
				if(c[j]==2) ans++;
				while(k+1<=r[j]&&dis[k+1]>dis[j]+1) dis[++k]=dis[j]+1;
				while(l+1<=n&&dis[l+1]<=dis[j]) ++l;
				if(max(l+1,j+1)<=min(k,r[j])) c[max(l+1,j+1)]+=c[j],c[min(k,r[j])+1]-=c[j];
			}
		}
		cout<<ans<<'\n';
	}
	void solve(){
		while(T--){
			Solve();
		}
	}
};
//namespace Subtask2{
//	void solve(){
//		
//	}
//};
signed main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	if(C<=10){Subtask1::solve();return 0;}
//	if(C==11||C==12){Subtask2::solve();return 0;}
	return 0;
}
