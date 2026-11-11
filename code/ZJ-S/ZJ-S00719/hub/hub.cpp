#include<bits/stdc++.h>
using namespace std;
int c,t;
vector<int>q[100005];
int a[100005];
int find(int x,int l){
	int cnt=x,k=1,kk=0;
	vector<int>p;
	a[x]++;
	p.push_back(q[x][0]);
	while(l--){
		for(int i=kk;i<k;i++){
			if(!a[p[i]]){
				a[p[i]]++;
				p.push_back(a[p[i]]);
			}
		}
		kk=k;
		k=p.size();
	}
}
void so1(int x){
	
}
int solve(int x,int l,int t){
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			q[i].clear();
			a[i]=0;
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			q[u].push_back(v);
			q[v].push_back(u);
		}
		int x,ans;
		for(int i=1;;i++){
			for(int j=1;j<=n;j++){
				if(q[j].size()==1){
					x=find(j,i-1);
					so1(x);
					ans=solve(k-1,i,1);
					if(ans)break;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
} 
