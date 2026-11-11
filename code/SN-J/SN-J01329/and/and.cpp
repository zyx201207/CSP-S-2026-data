#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long b[N],vis[N][31],n,m,k,ans;
vector<long long>a,c;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>b[i];
		a.push_back(i);
	}for(int i=1;i<=n;++i){
		for(long long j=0;j<=30;++j){
			vis[i][j]=((1ll<<j)&b[i]);
		}
	}
	for(long long j=30;j>=0;--j){
		k=0;
		c.clear();
		for(auto i:a){
			if(vis[i][j]){
				++k;
				c.push_back(i);
			}
		}if(k>=m){
			a=c;
			ans+=(1ll<<j);
		}
	}cout<<ans;
	return 0;
}
