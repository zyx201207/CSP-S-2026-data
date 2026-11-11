#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,m,d,q,w[500005],k[500005],a[500005],t[500005],x[500005],y[500005],z[5005][5005],f[500005][20],g[500005],r[500005],mn=1e9;
void dfs(ll X,ll Y,ll cnt){
	if(X==Y){
		for(int i=0;i<r[X];i++){
			mn=min(mn,cnt+z[X][f[X][i]]);
		}
		return;
	}
	
	for(int i=0;i<r[X];i++){
		dfs(f[X][i],Y,cnt+z[X][f[X][i]]);
		
	}
	return;
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
		cin>>a[j]>>t[j];
		if(j>1){
			z[a[j-1]][a[j]]=t[j];
			f[a[j-1]][r[a[j-1]]++]=a[j];
		}
		
	}
}

for(int i=1;i<=q;i++){
	cin>>x[i]>>y[i];
	dfs(x[i],y[i],w[x[i]]+w[y[i]]+1);
	cout<<mn<<endl;
	mn=1e9;
}


	return 0;
}
