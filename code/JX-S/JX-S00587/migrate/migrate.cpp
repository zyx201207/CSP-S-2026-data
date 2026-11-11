#include<bits/stdc++.h>
using namespace std;
const int N=2e6+6;
int C,T,n,d,a[N],lj[305],ans,mi[305];
void dfs(int x,int an){
	for(int i=x+1;i<=an;i++){
		if(a[i]-a[x]<=d&&mi[i]>mi[x]+1){
			mi[i]=mi[x]+1;
			lj[i]=lj[x];
			dfs(i,an);
		}else if(a[i]-a[x]<=d&&mi[i]==mi[x]+1) lj[i]+=lj[x],dfs(i,an);
		else if(a[i]-a[x]>d) return ;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n<=300){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					memset(mi,0x3f,sizeof(mi));
					mi[i]=0;
					lj[i]=1;
					dfs(i,j);
					if(lj[j]==2) ans++;
					memset(lj,0,sizeof(lj));
				}
			}
			cout<<ans<<'\n';
		}else cout<<0<<'\n';
	}
	return 0;
}
