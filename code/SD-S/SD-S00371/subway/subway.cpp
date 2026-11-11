#include<bits/stdc++.h>
using namespace std;
long long w[500005];
int k[25];
int a[505][25];
long long t[505][25];
long long at[15000][15000];
struct plans{
	int x;
	int y;
}p[100005];
long long ans[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	memset(at,0x3f3f3f3f,sizeof(at));
	for(int i=1;i<=m;i++){
		at[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j]; 
		}
	}
	for(int i=1;i<=q;i++){
		cin>>p[i].x>>p[i].y;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			for(int l=j;l<=k[i];l++){
				at[a[i][j]][a[i][l]]=min(at[a[i][j]][a[i][l]],(t[i][l]+t[i][j]));
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=i;j<=m;j++){
			for(int k=i;k<=j;k++){
				at[i][j]=min(at[i][j],at[i][k]+at[k][j]);
				at[j][i]=at[i][j];
			}
		}
	}
	for(int i=1;i<=q;i++){
		ans[i]+=w[p[i].x];
		ans[i]+=w[p[i].y];
		ans[i]+=at[p[i].x][p[i].y];
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
} 

