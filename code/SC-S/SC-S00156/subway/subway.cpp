#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=510,M=5e5+10,MN=5e7+10;
int c,n,m,d,q,mp[M*10],tot;
vector<pair<int,int> >G[MN];

int read(){
	int sum=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while('0'<=c&&c<='9'){
		sum=sum*10+(c-'0');
		c=getchar();
	}
	return sum;
}

int dist(int st,int ed){
	memset(mp,0,sizeof(mp));
	st=st+(n+2)*m,ed=ed+(n+2)*m;
	queue<pair<int,int> >q;
	q.push(make_pair(st,0));
	int ans=1e9,cnt=0;
	mp[st]=1;
	while(!q.empty()){
		int u=q.front().first,T=q.front().second;
		q.pop();
		if(u==ed){
			ans=min(ans,T);
			continue;
		}
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i].first,t=G[u][i].second;
			if(mp[v])continue;
			q.push(make_pair(v,T+t));
			mp[v]=1;
		}
	}
	return ans;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++){
		int w;
		w=read();
		G[i+m*(n+2)].push_back(make_pair(i,w));//i+m*(n+2)表示i的地铁口 
		G[i].push_back(make_pair(i+m*(n+2),w));
	}
	for(int i=1;i<=n;i++){
		int k,u;
		k=read();
		for(int j=1;j<=k;j++){
			int a1,t1;
			a1=read(),t1=read();
			if(j>1){
				G[i*m+u].push_back(make_pair(i*m+a1,0));
				G[i*m+a1].push_back(make_pair(i*m+u,0));
			}
			u=a1;
			G[a1].push_back(make_pair(i*m+a1,t1));//a1表示a1的站厅
			G[i*m+a1].push_back(make_pair(a1,t1));
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		x=read(),y=read();
		cout<<dist(x,y)<<endl;
	}
	
	return 0;
}
