#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 2000002
int c,t,n,k,U,V,maxx=-1,st1[N],minn=0x7fffffff;
bool a[100002];
vector<int> v[N];
void dfs(int m,int step,int fa){
//	cout<<step<<' '<<m<<'\n';
	for(int i=0;i<(int)v[m].size();i++){
		if(v[m][i]==fa)continue;
		if(a[v[m][i]]){
			minn=min(minn,step+1);
			return; 
		}
		dfs(v[m][i],step+1,m);
	}
}
int round(){
	minn=0x7fffffff;
	for(int i=1;i<=n;i++){
		if(a[i]==0)dfs(i,0,0);
//		cout<<i<<' ';
	}
	return minn;
}
queue<int> p;
void bfs(int s,int k){
	memset(a,0,sizeof a);
	int cnt=1;
	while(!p.empty())p.pop();
	p.push(s);
	a[s]=1;
	st1[cnt]=s;
	while(!p.empty()){
		int st=p.front();
		p.pop();
		for(int i=0;i<(int)v[st].size();i++){
			p.push(v[st][i]);
			cnt++;
//			cout<<cnt<<' ';
			st1[cnt]=v[st][i];
			a[v[st][i]]=1;
			if(cnt==k){
				maxx=max(maxx,round());
				return;
			}
		}
	}	
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		bool check3=1;
		int c3;
		cin>>n>>k;
		for(int i=1;i<=n;i++)v[i].clear();
		if(n%2==0)check3=0;
		else c3=n-1/2;
		for(int i=1;i<n;i++) {
			cin>>U>>V;
			if(i<=c3){
				if(U!=i||V!=i+1)check3=0;
			}
			else {
				if(U!=i-c3||V!=i+1)check3=0;
			}
			v[U].push_back(V);
			v[V].push_back(U);
		}
		if(check3){
			if(k>c3+1)cout<<"1 ";continue;
		}
		for(int i=1;i<=n;i++)
			bfs(i,k);
		cout<<maxx<<'\n';
		maxx=-1;
	}
	return 0;
}

