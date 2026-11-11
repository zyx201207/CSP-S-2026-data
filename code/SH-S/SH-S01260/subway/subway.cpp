#include<bits/stdc++.h>
using namespace std;
int a[505][50005],t[505][500005],w[500005],k[505],x[100005],y[100005],sum=0,mins=INT_MAX;
int c,n,m,d,q;
int dfs(int x,int y){
	if(x==y){
		int sum1=sum;
		sum=0;
		return sum1;
	}
	for(int i=x;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=x){
				sum+=t[i][j];
				sum+=dfs(a[i][j+1],y);
			}
		}	
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
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
		cin>>x[i]>>y[i];
		cout<<dfs(x[i],y[i])+w[x[i]]+w[y[i]];
	}

	return 0;
}

