#include<bits/stdc++.h>
using namespace std;
long long tx[500005],tex3[500005][10],tex2[500005][10],tex[500005],c,n,m,d,q,w[500005],k[500005],a[50000][500],t[50000][500],x,y,total;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int j=0;j<n;j++){
		cin>>k[j];
		for(int i=0;i<k[j];i++)
			cin>>a[i][j]>>t[i][j];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<k[i];j++){
			tex[a[j][i]]++;
			tex2[a[j][i]][tx[a[j][i]]]=t[j][i];
			tex3[a[j][i]][tx[a[j][i]]]=a[j+1][i];
			tx[a[j][i]]++;
		}
	}
	for(int i=0;i<q;i++){
		cin>>x>>y;
		total+=w[x];
		total+=tex2[x][0];
		for(int j=1;j<y-1;j++){
			total+=tex2[x+j][0];
			if(a[j+1][i]!=(x+j+1)){
				total+=tex2[a[j][0]][j];
			}
		}
		total+=tex2[y][0];
		total+=w[y];
		cout<<total<<endl;
		total=0;
	}
}
