#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005],x[500005],ans[300005],pre[500005],nxt[500005];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=x[a[i]];
		x[a[i]]=i;
		nxt[i]=i+1;
		nxt[pre[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) x[j]=0;
		for(int j=i;j<=n;j=nxt[j]){
			if(x[a[j]]==0) ans[a[j]]++;
			x[a[j]]=1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
