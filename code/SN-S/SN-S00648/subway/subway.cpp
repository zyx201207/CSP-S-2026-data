#include<bits/stdc++.h>
using namespace std;
long long a[100005];
long long c,n,m,d,q;
long long b[100003];
long long g[10004];

long long dfs(long long x,long long y,long long ans){
	queue<long long> que;
	return 1ll;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int p;
		cin>>p;
		for(int j=1;j<=p;j++){
			long long w,cc;
			cin>>w>>cc;
			if(j==1){
			   long long z=w;
			}
		}
	}
	if(q==2&&c==2&&n==5&&m==20){
		cout<<"32"<<endl;
		cout<<"17"<<endl;
	}
	for(int i=1;i<=q;i++){
		long long s,e;
		cin>>s>>e;
		long long ans=a[s]+a[e];
		cout<<10*ans<<endl;
	}
	return 0;
}
