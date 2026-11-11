#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500010;
int n,m,a[N],ans[N];
vector<int> p[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		int pre=n,nxt=0;
		for(int j=1;j<=m;j++){
			for(int k=1;k<p[j].size();k++){
				if(p[j][k-1]<i||k==p[j].size()) continue;
				pre=min(p[j][k-1],pre);
				nxt=max(p[j][k],nxt);
				k++;
			}
		}
		bool f[m+10];
		memset(f,0,sizeof f);
		if(nxt<pre){
			for(int j=i;j<=n;j++) f[a[j]]=1;
		} else {
			for(int j=i;j<pre;j++) f[a[j]]=1;
			for(int j=nxt;j<=n;j++) f[a[j]]=1;
		}
		for(int j=1;j<=m;j++) ans[j]+=f[j];
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	/*^_^*/
	return 0;
}

