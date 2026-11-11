#include<bits/stdc++.h>
using namespace std;
long long int n,m,d,q,w[500005],dir[505][505];
struct aa{
	long long int x,c;
};
vector<aa> a[500005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n;
	cin>>n>>m>>d>>q;
	for(int i=1; i<=m; i++){
		cin>>w[i];
	}
	for(int i=1; i<=n; i++){
		int l;
		cin>>l;
		while(l--){
			long long int x,c;
			cin>>x>>c;
			a[x].push_back({i,c});
		}
	}
	memset(dir,-1,sizeof(dir));
	for(int i=1; i<=n; i++){
		dir[i][i]=0;
	}
	for(int i=1; i<=m; i++){
		for(aa f:a[i]){
			for(aa k:a[i]){
				if(k.x==f.x)continue;
				long long int x=f.x,c=f.c,xx=k.x,cc=k.c;
				if(dir[x][xx]==-1||c+cc<dir[x][xx]){
					dir[x][xx]=c+cc;
					dir[xx][x]=cc+c;
				}
			}
		}
	}
	for(int i=1; i<=n; i++){
		for(int f=1; f<=n; f++){
			for(int k=1; k<=n; k++){
				if(f==k||i==f||i==k)continue;
				if(dir[f][i]==-1||dir[i][k]==-1)continue;
				if(dir[f][k]==-1||dir[f][i]+dir[i][k]<dir[f][k]){
					dir[f][k]=dir[f][i]+dir[i][k];
				}
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		long long int mn=1e18;
		for(aa i:a[x]){
			for(aa f:a[y]){
				if(dir[i.x][f.x]+i.c+f.c<mn&&dir[i.x][f.x]!=-1){
					mn=dir[i.x][f.x]+i.c+f.c;
				}
			}
		}
		cout<<mn+w[x]+w[y]<<endl;
	}
	return 0;
}