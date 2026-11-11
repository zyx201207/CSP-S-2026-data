#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int c,T;
int n,d,a[N],minn,cnt;
void dfs(int y,int z,int m){
	if(z==y){
		if(minn==m)cnt++;
		else if(m<minn){
			cnt=1;
		}
		minn=min(minn,m);
		return;
	}
	for(int i=z+1;i<=y;i++){
		if(a[i]>a[z]+d)return ;
		dfs(y,i,m+1);
	}
}
bool check(int x,int y){
	minn=2e6;
	cnt=1;
	dfs(y,x,0);
	if(cnt==2)return 1;
	else return 0;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==11||c==12){
			if(n<=3)cout<<0<<"\n";
			else {
				int u=d/(a[2]-a[1]);
				if(u==1)cout<<0<<"\n";
				else{
					ans=(n/u-1)*(n+1);
					if(n/u%2==0){
						ans-=u*((2+n/u)*(n/u/2-1)+n/u/2+1);
					}
					else {
						ans-=u*(2+n/u)*(n/u-1)/2;
					}
					cout<<ans<<"\n";
				}
			}
		}
		else{
			for(int i=1;i<=n-3;i++){
				for(int j=i+3;j<=n;j++){
					if(check(i,j))ans++;
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}


