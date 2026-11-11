#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL c,n,m,d,q1,cnt,zx[100005],w[100005],head[100005],k[100005],a[100005],t[100005];
struct edge{
	LL next,to,w;
}s[1000001];
void in(LL u,LL v,LL w){
	s[++cnt].w=w;
	s[cnt].to=v;
	s[cnt].next=head[u];
	head[u]=cnt;
}
queue<LL> q;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q1;
	for (int i=1;i<=m;i++) cin>>w[i];
	for (int i=1;i<=n;i++){
		cin>>k[i];
		for (int j=1;j<=k[i];j++) cin>>a[j]>>t[j];
		for (int j=1;j<=k[i];j++)
		  for (int l=j+1;l<=k[i];l++){
		  	in(a[j],a[l],t[j]+t[l]);
		  	in(a[l],a[j],t[j]+t[l]);
		  }
	}
	while (q1--){
		for (int i=1;i<=m;i++) zx[i]=1e18;
		LL st,nd;
		cin>>st>>nd;
		zx[st]=0;
		q.push(st);
		while (!q.empty()){
			LL now=q.front();
			q.pop();
			for (int i=head[now];i;i=s[i].next){
				if (s[i].w+zx[now]<zx[s[i].to]){
					zx[s[i].to]=s[i].w+zx[now];
					q.push(s[i].to);
				}
			}
		}
		cout<<zx[nd]+w[nd]+w[st]<<"\n";
	}
	return 0;
}
