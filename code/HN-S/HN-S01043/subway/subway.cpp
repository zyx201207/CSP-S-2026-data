#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int l,n,m,d,q;
int w[maxn],b[maxn],a[505][505],t[505][505],c[maxn];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>l>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1;i<=n;i++){
		int k;
		cin>>k;
		for (int j=1;j<=k;j++){
			int x;
			cin>>x>>t[i][x];
			if (b[x]==0) b[x]=i;
			c[x]++;
		}
	}
	for (int i=1;i<=q;i++){
		int x,y,ans;
		cin>>x>>y;
		ans+=w[x]+w[y];
		if (b[x]==b[y]) cout<<ans;
		else{
			int j=1;
			while (c[j]<2) j++;
			ans+=w[c[j]]+t[b[y]][c[j]];
		}
		cout<<ans<<endl;
	}
	return 0;
}
