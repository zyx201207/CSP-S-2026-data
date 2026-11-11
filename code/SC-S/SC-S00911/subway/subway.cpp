#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,sj[200005];
int x[100005],y[100005],w[500005];
int a[505][50005],t[505][50005];
int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		sj[i]+=w[x[i]];
		int z=1;
		for(int j=x[i];j<=y[i];j++){
			
			if(a[z][j]!=j){
				z=2;
				sj[i]+=t[z][j];
			}else{
				z=1;
				sj[i]+=t[z][j];
				
			}
			
			
		}
		sj[i]+=w[y[i]];
		cout<<sj[i]<<endl;
	}
	
	return 0;
}