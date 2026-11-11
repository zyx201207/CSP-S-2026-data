#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+5;
long long n,d,x[N],dis[N],f[N],ans;
vector<long long> e[N];
void bfs(long long u){
	memset(dis,0x3f,sizeof dis);
	memset(f,0,sizeof f);
	queue<long long> q;
	q.push(u);
	f[u]=1,dis[u]=0;
	while(!q.empty()){
		long long t=q.front();
		q.pop();
		for(auto v:e[t]){
			if(dis[v]>dis[t]+1){
				dis[v]=dis[t]+1;
				f[v]=f[t];
				q.push(v);
			}
			else if(dis[v]==dis[t]+1){
				f[v]+=f[t];
			}
		}
	}
	for(long long i=u+1;i<=n;i++){
		if(f[i]==2)ans++;
	}
}
long long L[N],R[N],s[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long c,t;
	cin>>c>>t;
	if(c==11||c==12){
	while(t--){
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>x[i];
		}
		long long X=x[2]-x[1];
		if(d<X*2){
			cout<<"0\n";
			continue;
		}
		d/=X;
		cout<<n-d-1<<'\n';
	}
	return 0;
	}
	if(c==13||c==14){
	while(t--){
		ans=0;
		memset(s,0,sizeof s);
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>x[i];
		}
		long long nex=1;
		for(long long i=1;i<=n;i++){
			while(nex<=n&&x[nex]-x[i]<=d)nex++;
			R[i]=nex-1;
			if(R[i]-i<=1)continue;
			s[R[i]-1]++;
		}
		nex=n;
		for(long long i=n;i>=1;i--){
			while(nex>0&&x[i]-x[nex]<=d)nex--;
			L[i]=nex+1;
			if(i-L[i]<=1)continue;
			ans+=s[L[i]];
		}
		cout<<ans<<'\n';
	}
	return 0;
	}
	while(t--){
		ans=0;
		cin>>n>>d;
		for(long long i=1;i<=n;i++)e[i].clear();
		for(long long i=1;i<=n;i++){
			cin>>x[i];
			for(long long j=i-1;j>0&&x[i]-x[j]<=d;j--){
				e[j].push_back(i);
			}
		}
		for(long long i=1;i<=n;i++){
			bfs(i);
		}
		cout<<ans<<'\n';
	}
	return 0;
}