#include<bits/stdc++.h>
using namespace std;
long long a[2000001];
int n;
long long dt;
vector<int> g[2000001];
int p[2000001];
int d[2000001];
int _lower_bound(int l,int r,int x){
	while(l<=r){
		int mid=(l+r)/2;
		if(a[x]-a[mid]>dt) l=mid+1;
		else r=mid-1;
	}
	return l;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--){
		int _max=0;
		cin>>n>>dt;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<=n;i++){
			cin>>a[i];
			int t=_lower_bound(1,i,i);
			for(int j=t;j<i;j++) g[j].push_back(i);
		} 
		for(int kk=1;kk<=n;kk++){
			memset(d,0x3f3f3f3f,sizeof(d));
			memset(p,0,sizeof(p));
			queue<int> q;
			q.push(kk);
			d[kk]=0;
			while(!q.empty()){
				int t=q.front();
				q.pop();
				for(int i=0;i<g[t].size();i++){
					int x=g[t][i];
					if(d[x]==d[t]+1) p[x]++;
					if(d[x]>d[t]+1){
						d[x]=d[t]+1;
						p[x]=1; 
						q.push(x);
					}
				}
			}	
			for(int i=1;i<=n;i++){
				if(p[i]==2) _max++;
			} 
		}
		cout<<_max<<"\n";
	}
	return 0;
}
