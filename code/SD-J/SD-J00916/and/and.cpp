#include<bits/stdc++.h>
using namespace std;

vector<int> v;
long long n,m;

int maxn=0;

void dfs(int c,int x,int s){
//	cout<<c<<" "<<x<<" "<<s<<"\n";
	if(c==m){
		maxn=max(maxn,x);
		return;
	}
	
	if(s>n) return;
	dfs(1,v[s],s+1);
	dfs(c+1,(x=(x&v[s])),s+1);
	dfs(c,x,s+1);
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n>>m;
	
	for(long long i=0;i<n;i++){
		long long x;
		cin>>x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	
	if(m==n){
		int ans=v[0];
		for(int i=1;i<n;i++){
			ans&=v[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		int maxn=0;
		for(int i=0;i<n;i++){
			maxn=max(maxn,v[i]);
		}
		cout<<maxn;
		return 0;
	}
	if(m==2){
		int maxn=0;
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				if(j==i) continue;
				maxn=max(maxn,v[i]&v[j]);
			}
		}
		cout<<maxn;
		return 0;
	}
	dfs(0,0,0);
	cout<<maxn;
	return 0;
}

