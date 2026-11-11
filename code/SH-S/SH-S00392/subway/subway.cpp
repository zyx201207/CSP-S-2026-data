#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll w[510];
int a[1010][1010],x[1010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(a,0x3f,sizeof a);
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x[j];
			cin>>x[j];
			cin>>a[x[j]][x[j]+m];
			for(int l=1;l<=j;l++){
				a[x[j]][x[l]]=0;
			}
		}
	}
	for(int k=1;k<=2*m;k++){
		for(int i=1;i<=2*m;i++){
			for(int j=1;j<=2*m;j++){
				if(a[i][k]+a[k][j]<=a[i][j]) a[i][j]=a[i][k]+a[k][j];
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<a[x][y]+w[x]+w[y]<<"\n";
	} 
	return 0;
}
