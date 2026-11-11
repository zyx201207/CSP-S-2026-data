#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[500001],lc[510][510],vic[510];
int a,t[510][500001];int k[500001],b[500001][21],cnt[500001],f,r;
int s[25000000];
inline void bfs(int x){
	memset(vic,0x3f,sizeof(vic));
	f=1;r=1;
	s[1]=x;
	vic[x]=0;
	while(f<=r){
		int y=s[f++];
		for(int l=1;l<=n;l++){
			if(lc[y][l]!=0&&lc[y][l]!=0x3f&&l!=y&&vic[l]>lc[y][l]+vic[y]){
				vic[l]=lc[y][l]+vic[y];
				s[++r]=l;
			}
		}
	}

	for(int i=1;i<=n;i++){
		if(lc[x][i]!=0&&lc[x][i]!=0x3f&&vic[i]>=lc[x][i]){
			continue;
		}
		if(i!=x)
		lc[x][i]=vic[i];
		if(i!=x)
		lc[i][x]=vic[i];
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a>>t[i][a];
			b[a][++cnt[a]]=i;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=cnt[i];j++){
			for(int k=j+1;k<=cnt[i];k++){
				if(j!=k){
					lc[j][k]=min(1ll*t[b[i][j]][i]+1ll*t[b[i][k]][i],lc[j][k]);
					lc[k][j]=min(lc[k][j],t[b[i][j]][i]*1ll+1ll*t[b[i][k]][i]);
					if(lc[k][j]==0){
					lc[j][k]=t[b[i][j]][i]*1ll+t[b[i][k]][i]*1ll;
					lc[k][j]=t[b[i][j]][i]*1LL+t[b[i][k]][i]*1ll;
					}
				}
			}
		}
	}

	for(int i=1;i<=n;i++){
		bfs(i);
	}
	for(int op=1;op<=q;op++){
		int x,y;long long ans=1000000000000000;
		cin>>x>>y;
		for(int j=1;j<=cnt[x];j++){
			for(int k=1;k<=cnt[y];k++){
				long long T=t[b[x][j]][x]+t[b[y][k]][y];
				if(lc[b[y][k]][b[x][j]]!=0)
				ans=min(ans+T,T+lc[b[y][k]][b[x][j]]);
				if(lc[b[x][j]][b[y][k]]!=0){
					ans=min(ans+T,T+lc[b[x][j]][b[y][k]]);
				}
				if(b[x][j]==b[y][k]){
					ans=0+T;
					break;
				}
				
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}