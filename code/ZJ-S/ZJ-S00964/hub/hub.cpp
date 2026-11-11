#include <bits/stdc++.h>
using namespace std;
int c,T,n,k,mi,u,v,d[100010],b[100010],i;
bool fl[100010],flag[100010],f;
vector <int> a[100010];
void sc3(int t,int s,int mb){
	int i;
	if(f) return ;
	if(fl[t]){d[mb]=s;f=1;return ;}
	for (i=0;i<a[t].size();i++)
		if(!flag[a[t][i]])
			flag[a[t][i]]=1,sc3(a[t][i],s+1,mb);
}
void sc2(int t){
	int i;
	for (i=0;i<a[t].size();i++)
		if(fl[a[t][i]]&&!flag[a[t][i]])
			flag[a[t][i]]=1,sc2(a[t][i]);
}
void sc(int x,int t){
	int s,ma,i;
	if(t==k+1){
		s=0;ma=0;
		for (i=1;i<=k;i++)
			if(!flag[b[i]]&&s==2) return ;
			else s++,flag[b[i]]=1,sc2(b[i]);
		memset(flag,0,sizeof(flag));
		for (i=1;i<=n;i++)
			f=0,flag[i]=1,sc3(i,0,i),ma=max(ma,d[i]),memset(flag,0,sizeof(flag));
		mi=min(mi,ma);
		return ;
	}
	if(x==n+1) return ;
	sc(x+1,t);
	b[t]=x,fl[x]=1;
	sc(x+1,t+1);
	b[t]=0,fl[x]=0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;mi=2e9;
		for (i=1;i<n;i++)
			cin>>u>>v,a[u].push_back(v),a[v].push_back(u);
		sc(1,1);
		cout<<mi<<"\n";
		for (i=1;i<=n;i++)
			while(a[i].size())
				a[i].pop_back();
	}
	return 0;
}
