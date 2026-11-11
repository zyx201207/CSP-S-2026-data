#include <bits/stdc++.h>
using namespace std;
long long n,m,vis[105],b[35]={1},ans,k;vector<long long>a;
bool cmp(long long a,long long b){
	return a>b;
}
vector<long long> dfs(long long p){
	vector<long long>s;
	for(int i=0;i<a.size();++i){
		if((a[i]&b[p])==b[p]){
			s.push_back(a[i]);
		}
	}
	return s;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=1;i<=30;++i) b[i]=b[i-1]*2;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		long long o;cin>>o;a.push_back(o);
	}
	for(int i=30;i>=0;--i){
		vector<long long>s=dfs(i);
		long long po=s.size();
		if(po>=m) ans+=b[i],a=s;
	}
	cout<<ans;
	
	return 0;
}