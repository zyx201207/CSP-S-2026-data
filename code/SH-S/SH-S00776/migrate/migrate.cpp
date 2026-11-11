#include<bits/stdc++.h>
typedef long long ll;
using std::cin;
using std::cout;
constexpr int N=5e3+9;
int c,T,n,nxt[N];
ll d,x[N],ans;
ll w[N][N],cnt[N][N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++)nxt[i]=std::upper_bound(x+1,x+1+n,x[i]+d)-x-1;
		for(int i=1;i<n;i++){
			w[i][i+1]=cnt[i][i+1]=(x[i+1]-x[i]<=d);
		}
		for(int k=2;k<n;k++){
			for(int i=1,j=k+1;j<=n;i++,j++){
				cnt[i][j]=0;
				if(!cnt[i][j-1]||!cnt[i+1][j]){w[i][j]=0;continue;}
				if(j<=nxt[i]){w[i][j]=cnt[i][j]=1;continue;}
				w[i][j]=1+w[nxt[i]][j];
				for(int x=nxt[i];w[x][j]==w[nxt[i]][j]&&x>i;x--){
					cnt[i][j]+=cnt[x][j];
				}
				if(cnt[i][j]==2)++ans;
				#ifdef DEBUG
				if(cnt[i][j]==2)cout<<i<<' '<<j<<'\n';
				#endif
			}
		}
		cout<<ans<<'\n';
		#ifdef DEBUG
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cout<<cnt[i][j]<<" \n"[j==n];
		#endif
	}
	return 0;
}

// sure 24pts... want 40pts... should 56pts...