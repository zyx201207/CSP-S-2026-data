#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int d[N],ans;
vector<int> a[N];
void build(int fa,int x){
	if(a[x].size()==1) d[x]=1;
	for(auto it:a[x]){
		if(fa!=it) {
			build(x,it);
			d[x]=max(d[x],d[it]+1);
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		build(0,1);
		for(int i=1;i<=n;i++) cout<<d[i]<<" ";
		priority_queue<int> q;
		for(auto it:a[1])
			q.push(it);
		int k1=q.top();
		q.pop();
		int k2=q.top();
		cout<<(k1+k2)/k<<endl;
	}
	
	return 0;
}