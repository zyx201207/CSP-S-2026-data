#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,st[505][505],a[100005],k,aa,t,cnt[500005],xr,yr,ans=-1;
queue<int>b[500005];
queue<int>ti[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(st,-1,sizeof(st));
	memset(cnt,0,sizeof(cnt));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		st[i][i]=0;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>aa>>t;
			if(cnt[aa]!=0){
				for(int l=1;l<=cnt[aa];l++){
					int lll=b[aa].front();
					int tt=ti[aa].front();

					b[aa].pop();
					b[aa].push(lll);
					ti[aa].pop();
					ti[aa].push(tt);
					if(st[i][lll]==-1){

						st[lll][i]=t+tt;
						st[i][lll]=t+tt;
					}
					else if(t+tt<st[lll][i]){

						st[lll][i]=t+tt;
						st[i][lll]=t+tt;
					}
				}
			}
			cnt[aa]++;
			b[aa].push(i);
			ti[aa].push(t);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(i==j||j==k||i==k)continue;
				if(st[i][k]==-1||st[k][j]==-1)continue;
				if(st[i][j]==-1){
					st[i][j]=st[i][k]+st[k][j];
				}
				else{
					st[i][j]=min(st[i][j],st[i][k]+st[k][j]);
				}
			}
		}
	}
	while(q--){
		cin>>xr>>yr;
		ans=-1;
		for(int i=1;i<=cnt[xr];i++){
			int xd=b[xr].front(),xt=ti[xr].front();
			b[xr].pop();
			b[xr].push(xd);
			ti[xr].pop();
			ti[xr].push(xt);
			for(int j=1;j<=cnt[yr];j++){
				int yd=b[yr].front(),yt=ti[yr].front();
				b[yr].pop();
				b[yr].push(yd);
				ti[yr].pop();
				ti[yr].push(yt);
				if(st[xd][yd]!=-1){
					if(ans==-1){
						ans=xt+yt+st[xd][yd];
					}
					else ans=min(ans,xt+yt+st[xd][yd]);
				}
			}
		}
		cout<<ans+a[xr]+a[yr]<<"\n";
	}
	return 0;
}
