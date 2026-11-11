#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,M=5e5+1;
int c,n,m,d,q,w[N],k[N],fa[M],siz[M];
unordered_map<int,int> b[N],p[N];
void init(){for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;}
int fid(int x){return x==fa[x]?fa[x]:fa[x]=fid(fa[x]);}
void Union(int x,int y){
	x=fid(x),y=fid(y);
	if(siz[x]<siz[y]) swap(x,y);
	fa[y]=x;
	siz[x]+=siz[y];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>b[i][j]>>p[b[i][j]][i];
			if(j>1) Union(b[i][j],b[i][j-1]);
		}
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		bool flg=0,flg2=0,flg1=0;
		int t=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(b[i][j]==l) flg=1;
				if(b[i][j]==r) flg2=1;
			}
			if(flg&&flg2){
				flg1=1;
				t=i;
				break;
			}
			else flg=flg2=0;
		}
		if(flg1) cout<<w[l]+w[r]+2*p[l][t]<<"\n";
		else cout<<w[l]+w[r]+4*p[l][t]<<"\n";
	}
	return 0;
}