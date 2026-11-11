#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e6+5;
int n,m,cnt,a[N];
int f[N],in[N],sum[N];
int h[N],to[N],nxt[N];
void add(int a,int b){
	cnt++;
	in[b]++;
	to[cnt]=b;
	nxt[cnt]=h[a];
	h[a]=cnt;
}
void topusort(){
	queue<int>q;
	for(int i=1;i<=n;i++)
		if(!in[i]) q.push(i);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=h[u];i;i=nxt[i]){
			int x=to[i];
			in[x]--,sum[x]+=sum[u];
			if(in[x]==0) q.push(x);
		}
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],f[a[i]]=i,sum[a[i]]++;
	for(int i=1;i<=m;i++)
		if(f[i]!=n) add(i,a[f[i]+1]);
	topusort();
	for(int i=1;i<=m;i++)
		cout<<sum[i]<<" ";
	return 0;
}