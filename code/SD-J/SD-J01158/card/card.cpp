#include<bits/stdc++.h>
using namespace std;
const int N=500007;
const int M=300007;
int n,m,ans[M];
int a[N];
int v[M],w[M];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(v,0,sizeof(v));
		memset(w,0,sizeof(w));
		for(int j=i;j<=n;j++) {
			if(v[a[j]]!=0) 
				for(int k=w[a[j]];k<=j;k++) v[a[k]]=0;
			v[a[j]]=1,w[a[j]]=j;
		}
		for(int j=1;j<=m;j++) ans[j]+=v[j];
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
