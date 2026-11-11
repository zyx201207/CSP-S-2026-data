#include<bits/stdc++.h>
using namespace std;
int c,n,m,d1,q;
int w[500005],biao[505][50005],k[505];
int d[505][50005];
vector<int>p[50005],kk[505];
void luxin(int xian,int muxian,int jie,int mu,int ans){
//	cout<<xian<<' '<<jie<<' '<<ans<<'\n';
//	ans+=d[xian][jie];
	int pain=0;
	if(muxian>xian)pain=1;
	else if(muxian<xian)pain=-1;
	if(jie==mu){
		ans+=(w[mu]);
		cout<<ans<<'\n';
		return;
	}
	else{
		for(int i=0;i<k[xian];i++){
			
			if(kk[xian][i]==mu){
				ans+=d[xian][mu];
				luxin(xian,muxian,kk[xian][i],mu,ans);
				return;
			}
			else if(biao[xian+pain][kk[xian][i]]&&pain!=0){
				ans+=d[xian][kk[xian][i]];
				ans+=d[xian+pain][kk[xian][i]];
				luxin(xian+pain,muxian,kk[xian][i],mu,ans);
				return;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d1>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,t;
			cin>>a>>t;
			d[i][a]=t;
			biao[i][a]=1;
			p[a].push_back(i);
			kk[i].push_back(a);
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int xianxi=1,xianyi=1,maxn=0x3f3f3f3f;
		for(int j=0;j<p[x].size();j++){
			for(int j2=0;j2<p[y].size();j2++){
				if(abs(p[x][j]-p[y][j2])<maxn){
					maxn=abs(p[x][j]-p[y][j2]);
					xianxi=p[x][j];
					xianyi=p[y][j2];
				}
			}
		}
//		cout<<xianxi<<' '<<xianyi<<endl;
		luxin(xianxi,xianyi,x,y,w[x]+d[xianxi][x]);
		
	}
	return 0;
}
