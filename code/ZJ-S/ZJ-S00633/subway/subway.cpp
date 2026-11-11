#include<bits/stdc++.h>
using namespace std;
int c,n,m,D,T,l,r,ans,w[500010],p[500010],tt[510][500010];
int f[500010],used[500010];
vector <int> a[500010],b[500010],d[500010];
void dj(int s){
	int ww;
	memset(f,31,sizeof(f));
	memset(used,0,sizeof(used));
	priority_queue <int,vector <int> ,greater <int> > q;
	q.push(s);
	f[s]=0;used[s]=1;
	while(!q.empty()){
		int u=q.top();q.pop();
		for(int i=0;i<a[u].size();i++){
			int v=a[u][i];
			if(b[u].size()==0)ww=d[u][i];
			else if(d[u].size()==0)ww=b[u][i];
			else
				if(i==0)ww=d[u][i];
				else if(i==1)ww=b[u][i];
				else
					if(v>u)ww=b[u][i];
					else ww=d[u][i];
			if(used[v])continue;
			if(f[v]>f[u]+ww)f[v]=f[u]+ww;
			q.push(v);
			used[v]=1;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>m>>n>>D>>T;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1,x;i<=m;i++){
		cin>>x;
		for(int j=1,t;j<=x;j++){
			cin>>p[j]>>t;
			p[j]+=(m-1)*n;
			if(j<x){
				a[p[j]].push_back(p[j+1]);
				a[p[j+1]].push_back(p[j]);
				b[p[j]].push_back(t);
				d[p[j+1]].push_back(t);
			}
			tt[i][p[j]]=t;
		}
	}
	if(D>1)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				for(int k=1;k<=m;k++)
					if(j!=k){
						a[i+(j-1)*n].push_back(i+(k-1)*n);
						a[i+(k-1)*n].push_back(i+(j-1)*n);
						b[i+(j-1)*n].push_back(tt[j][i+(j-1)*n]);
						d[i+(k-1)*n].push_back(tt[k][i+(k-1)*n]);
					}
	while(T--){
		cin>>l>>r;ans=1e18;
		for(int i=1;i<=m;i++){
			dj(l+(i-1)*n);
			for(int j=1;j<=m;j++)ans=min(ans,f[r+(j-1)*n]);
		}
		cout<<ans+w[l]+w[r]<<"\n";
	}
}