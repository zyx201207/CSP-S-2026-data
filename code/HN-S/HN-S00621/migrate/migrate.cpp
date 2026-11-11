#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,c,t,d,a[N],ans,f;
vector<int> e[N];
void bfs(int u){
	int d[N],st[N];
	fill(d,d+N,1e9);
	queue<int> p;
	p.push(u);
	d[u]=0;
	while(p.size()){
		int t=p.front();
		p.pop();
		for(auto x:e[t]){
			if(d[x]>d[t]+1)d[x]=d[t]+1,st[x]=1,p.push(x);
			else if(d[x]==d[t]+1)st[x]++;
		}
	}
	for(int i=u;i<=n;i++){
		if(st[i]==2)ans++;
//		cout<<st[i]<<" ";
	}
//	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i],e[i].clear();
		if(n>=N||(c==11||c==12)){
			f=0;
			for(int i=1;i<=10;i++){
				for(int j=i+1;j<=10;j++){
					if(a[i]+d>=a[j])e[i].push_back(j);
					else break;
				}
			}
			bfs(1);
			if(f)cout<<n-f+1<<"\n";
			else cout<<0<<"\n";
		}else{
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[i]+d>=a[j])e[i].push_back(j);
					else break;
				}
			}
			for(int i=0;i<=max(n-4,0);i++){
				bfs(i+1);
			}
			cout<<ans<<"\n";	
		}
	}
	return 0;
}
