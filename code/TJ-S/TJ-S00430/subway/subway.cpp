#include<bits/stdc++.h>
using namespace std;
int mi=1e9,c,n,m,d,q,w[500005],t[505][505],a[505][505],x[100005],y[100005],k[505],bj[500005];
//void suan(int qi,int sum,int r,int zh){
//	if(q1==zhong){
//		mi=min(mi,sum);	
//	}
//	for(i=1;i<=k[r];i++){
//		if
//		if(bj[a[r][i]]==0){
//			bj[a[r][i]]=0;
//			suan(a[r][i],sum)
//		}
//	}
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=i;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		int sum=w[x[i]]+w[y[i]];
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=k[i];j++){
//				if(a[i][j]==x[i]){
//					suan(x[i],sum,i,y[i]);
//				}
//			}
//		}
		cout<<sum+t[1][x[i]]+t[1][y[i]]<<"\n";
	}
	return 0;
}

