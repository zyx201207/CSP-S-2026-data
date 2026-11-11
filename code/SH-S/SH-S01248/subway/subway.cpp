#include<bits/stdc++.h>
#define ll long long
const ll N=5e5+10;
const ll M=4e3+10;
ll d[M][M];
ll a[N],t[N];
ll w[N],x[N],y[N];
ll c,n,m,di,q;
using namespace std;
int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>di>>q;
	memset(d,0x3f,sizeof d);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		memset(a,0,sizeof a);
		memset(t,0,sizeof t);
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int j=2;j<=k;j++){
			d[a[j-1]][a[j]]=min(d[a[j-1]][a[j]],t[j-1]+t[j]);
//			cout<<d[a[j-1]][a[j]]<<endl;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	
	for(int i=1;i<=q;i++){
//		cout<<"x="<<x[i]<<" "<<"y="<<y[i]<<endl;
//		cout<<d[x[i]][y[i]]<<endl;
		cout<<w[x[i]]+w[y[i]]+d[x[i]][y[i]]<<endl;
	}
	return 0;
	
	fclose(stdin);
	fclose(stdout);
}
