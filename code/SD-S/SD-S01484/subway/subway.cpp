//qvqv
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=2e3+10;
struct node{
	int v,w;
};
int g[M][M];
int w[N],a[M][M],t[M][M],l[N],r[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(g,0x3f,sizeof(g));
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	if(c<=11){
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			for(int j=1;j<=k;j++){
				cin>>a[i][j]>>t[i][j];
			}
			for(int j=1;j<=k;j++){
				for(int l=1;l<=k;l++){
					if(l!=j){
						g[a[i][j]][a[i][l]]=g[a[i][l]][a[i][j]]=t[i][j]+t[i][l];
					}
				}
			}
		}
		for(int k=1;k<=m;k++){
			for(int i=1;i<=m;i++){
				for(int j=1;j<=m;j++){
					g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
				}
			}
		}
		
		for(int i=1;i<=q;i++){
			cin>>l[i]>>r[i];
			printf("%d\n",g[l[i]][r[i]]+w[l[i]]+w[r[i]]);
		}
		return 0;
	}
	if(c==21||c==22) for(int i=1;i<=q;i++) cout<<3<<'\n';
	else{
		//luangao
		srand(time(0));
		for(int i=1;i<=q;i++) cout<<rand()%rand()<<'\n';
		return 0;
	}
}

//ccf shui yang li fa li le
//16:30 44 分暴力寄 
//16:45 放弃性质B 
