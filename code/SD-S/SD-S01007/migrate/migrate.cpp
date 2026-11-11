#include<bits/stdc++.h>
#define N 2000005
#define int long long 
using namespace std;
int c,T,n,d,x[N],lst[N];
int f[5005][5005],g[5005][5005],s[5005][5005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>x[i];
		}
		for(int i=1;i<=n;++i){
			lst[i]=lower_bound(x+1,x+n+1,x[i]-d)-x;
		}
		if(13<=c&&c<=14){
			int ans=0;
			for(int i=1;i<=n;++i){
				int nxt=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
				int pos1=lower_bound(lst+1,lst+n+1,nxt-1)-lst;
				int pos2=lower_bound(lst+1,lst+n+1,nxt)-lst;
				ans+=pos2-pos1;
				if(lst[nxt]==nxt-1)--ans;
				if(lst[nxt-1]==nxt-1)--ans;
			}
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j)f[i][j]=g[i][j]=s[i][j]=0;
		}
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				f[i][j]=f[i][lst[j]]+1;
				//cout<<i<<" "<<j<<" "<<f[i][j]<<'\n';
			}
		}
		int cnt=0;
		for(int k=1;k<=n;++k){
			g[k][k]=s[k][k]=1;
			for(int i=k+1;i<=n;++i){
				int l=max(k,lst[i]),r=i-1;
				if(l<=r){
					int v=f[k][i]-1;
					if(f[k][l]<=v){
						int ql=l,qr=r,ans=r;
						while(ql<=qr){
							int mid=(ql+qr)>>1;
							if(f[k][mid]==v)ans=mid,ql=mid+1;
							else qr=mid-1;
						}
						g[k][i]=min(s[k][ans]-s[k][l-1],3ll);
						if(g[k][i]==2)++cnt;
					}
					s[k][i]=s[k][i-1]+g[k][i];
				}
			}
		}
		cout<<cnt<<'\n';
		
	}
	return 0;
}
/*
0 1
9 5
0 1 2 3 4 5 7 9 10

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
