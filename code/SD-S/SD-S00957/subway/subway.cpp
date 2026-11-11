#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],s[505][505],a[500005],x,y,t[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	memset(s,0x3f,sizeof(s));
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&a[j],&t[j]);
			for(int l=1;l<=j;l++){
				s[a[j]][a[l]]=t[j]+t[l];
				s[a[l]][a[j]]=t[j]+t[l];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int l=1;l<=m;l++){
				s[i][j]=min(s[i][j],s[i][l]+s[l][j]);
			}
		}
	}
	while(q--){
		scanf("%d%d",&x,&y);
		printf("%d\n",s[x][y]+w[x]+w[y]);
	}
	return 0;
}
