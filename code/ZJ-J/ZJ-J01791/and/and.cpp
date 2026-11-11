#include<bits/stdc++.h>

using namespace std;

#define int long long
// DANGEROUS
#define ll long long
#define il inline

const int N=2e5+5,mod=1e9+7;

int n,m,ans;
int a[N];
int b[N],cnt;
bool vis[N];

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;cnt=n;
	for(int i=1;i<=n;i++) cin>>a[i],b[i]=a[i];
	for(int mask=30;mask>=0;mask--){
		int now=(1LL<<mask),del=0;
		for(int j=1;j<=cnt;j++) if((b[j]&now)==0) vis[j]=1,del++;
		if(cnt-del<m){
			for(int j=1;j<=cnt;j++) vis[j]=0;
			continue;
		}
		int newcnt=0;
		for(int j=1;j<=cnt;j++){
			if(!vis[j]) b[++newcnt]=b[j];
			else vis[j]=0;
		}
		cnt=newcnt;
		ans+=now;
	}
	cout<<ans;
	return 0;
}/*
Code by RhMoGe
Luogu uid = 1634173
Last Dance.
AFO soon.
*/
