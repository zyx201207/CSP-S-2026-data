#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,fl,x,a[500010],g[500010],f[500010],b[500010],ans[500010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;fl=1;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if(a[i]<a[i-1]&&i!=1)fl=0;
	}
	if(n>5000&&m==1){
		cout<<n;
		return 0;
	}
	if(fl==1){
		for(int i=1;i<=n;i++)
		    if(a[i]!=a[i+1])ans[a[i]]=i;
		ans[m]=n;
		for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
		return 0;
	}
		for(int i=1;i<=n;i++)g[a[i]]=i;
		g[a[n]]=n+1;
		for(int i=1;i<=n;i++){
			x=i;
		    while(x<=n){
		    	ans[a[x]]++;
		    	x=g[a[x]]+1;
		    }
		}
        for(int j=1;j<=m;j++)cout<<ans[j]<<" ";
	return 0;
}
