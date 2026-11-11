#include<bits/stdc++.h>
using namespace std;
int w[500010];
long long mp[510][510];
int t[22][500010],a[22][500010];
int tot[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			mp[i][j]=1e18;
		mp[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int aa,tt;
			scanf("%d%d",&aa,&tt);
			for(int l=1;l<=tot[aa];l++){
				int go=a[l][aa],e=t[l][aa];
				if(mp[go][i]>e+tt){
					
					mp[go][i]=e+tt;
					mp[i][go]=e+tt;
				}
			}
			++tot[aa];
			a[tot[aa]][aa]=i;
			t[tot[aa]][aa]=tt;
		}
	}	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			for(int l=j+1;l<=n;l++){
				if(j!=l&&i!=l){
					if(mp[j][l]>mp[j][i]+mp[i][l]){
						mp[j][l]=mp[j][i]+mp[i][l];
						mp[l][j]=mp[j][i]+mp[i][l];
					} 
				}
			}
		}
	}
	while(q--){
		int aa,bb;
		scanf("%d%d",&aa,&bb);
		long long ans=1e18;
		for(int i=1;i<=tot[aa];i++){
			for(int j=1;j<=tot[bb];j++){
				ans=min(ans,mp[a[i][aa]][a[j][bb]]+t[i][aa]+t[j][bb]);
			}
		}
		printf("%lld\n",ans+w[aa]+w[bb]);
	}
	return 0;
}
