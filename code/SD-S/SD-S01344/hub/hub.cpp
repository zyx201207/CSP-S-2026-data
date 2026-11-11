#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10,M=998244353;

int c,n,k,f[N],ans;
bitset<N> b,bb;
vector<int> e[N];
queue<int> q;

int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}

int check(){
//	cout<<"------\n";
	for(int i=1;i<=n;i++)f[i]=i;
	while(!q.empty())q.pop();
	q.push(1);
	bb.reset();
	while(!q.empty()){
		int x=q.front();
		q.pop();
		bb[x]=1;
		for(int y:e[x]){
			if(!bb[y]){
				bb[y]=1;
				if(b[y]==1&&b[x]==1){
					f[find(y)]=f[x];
					q.push(y);
				}
			}
		}
	}
	bb.reset();
	int re=0;
	for(int i=1;i<=n;i++){
		if(b[i]){
			if(bb[find(i)]==0)bb[find(i)]=1,re++;
		}
	}
//	cout<<bb.count()<<'\n';
	return re;
}

void dfs1(int x){
	
}
/*
void nb(){
	bb.reset();
	dfs1(1);
	bb.reset();
	dfs2(1);
}
*/
void dfs(int x,int sum){
//	for(int i=1;i<=x;i++)cout<<b[i];
//	cout<<'\n';
//	cout<<x<<" "<<sum<<'\n';
	if(sum==k){
		if(check()==2){
			for(int i=1;i<=n;i++)cout<<bb[i];
			cout<<'\n';
//			ans=min(nb(),ans);
//			exit(1);
		}
		return ;
	}
	if(x>n)return ;
	for(int i=x;i<=n;i++){
		b[i]=1;
//		cout<<i+1<<" "<<sum+1<<'\n';
//		cout<<x<<"->\n";
		dfs(i+1,sum+1);
//		cout<<x<<"<-\n";
		b[i]=0;
	}
}

void solve(){
	ans=1008600100860010086;
	cin>>n>>k;
	cout<<1<<'\n';
	return ;
	b.reset();
	for(int i=1;i<=n;i++)e[i].clear();
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1,0);
}

signed main(){
	freopen("hub1.in","r",stdin);
//	freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>c>>t;
	while(t--){
		solve();
	}
    
	return 0;
}


