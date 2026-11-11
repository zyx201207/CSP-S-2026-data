#include<bits/stdc++.h>
using namespace std;
long long jl[40][200010],a[200010];
bool vis[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<=32;j++){
			jl[j+1][i]=((a[i]>>j)&1);
		}
	}
	long long ans=0;
	for(int i=31;i>=0;i--){
		long long l=0;
		for(int j=1;j<=n;j++){
			l+=((!vis[j])&&((a[j]>>i)&1));
		}
		if(l>=m){
			ans+=(1ll<<i);
			for(int j=1;j<=n;j++){
				vis[j]|=!((a[j]>>i)&1);
			}
		}
	}
	cout<<ans;
	return 0;
}
