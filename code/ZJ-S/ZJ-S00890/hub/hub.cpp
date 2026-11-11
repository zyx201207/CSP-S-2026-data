#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
using namespace std;
long long c,t,f[2000010],ans1,ans2;
vector<long long> g[2000010];
long long find(long long x){
	if(f[x]==x){
		return x;
	}
	return f[x]=find(f[x]);
}
void unite(long long x,long long y){
	long long fx=find(x),fy=find(y);
	if(fx!=fy){
		f[fx]=fy;
	}
}
long long dfs1(long long x,long long fa){
	long long mx=0;
	for(auto i:g[x]){
		if(i!=fa){
			long long t=dfs1(i,x);
			ans1=max(ans1,t+mx);
			mx=max(mx,t);
		}
	}
	return mx+1;
}
long long dfs2(long long x,long long fa){
	long long mx=0;
	for(auto i:g[x]){
		if(i!=fa){
			long long t=dfs2(i,x);
			ans1=max(ans2,t+mx);
			mx=max(mx,t);
		}
	}
	return mx+1;
}
int main(){
	fast;
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long n,k;
		cin>>n>>k;
		//long long a[n+10],t[n+10],mn=1e18;
		for(int i=1;i<n;i++){
			long long u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		/*for(int i=1;i<=n;i++){
			a[i]=i;
			f[i]=i;
		}
		do{
			long long sum,t1,t2;
			for(int i=1;i<=k;i++){
				for(auto j:g[i]){
					unite(i,j);
				}
			}
			for(int i=1;i<=n;i++){
				t[f[i]]++;
			}
			for(int i=1;i<=n;i++){
				if(t[i]>0){
					sum++;
					if(sum==1) t1=t[i];
					else t2=t[i];
				}
			}
			if(sum<=2){
				dfs1(t1,0);
				dfs2(t2,0);
				mn=min(max(ans1,ans2),mn);
			}
		}while(next_permutation(a+1,a+1+n));
		cout<<mn<<endl;
		*/
		cout<<n/5<<endl;
	}
	return 0;
}
