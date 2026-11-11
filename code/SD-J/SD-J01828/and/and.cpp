#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define ull unsigned long long
ll a[200010][35],n,m,ans=0,vis[200010][35],last=34;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		ll x;
		cin>>x;
		for(int j=0;j<=30;j++) a[i][j]=(x>>j)&1;
	}
	for(int j=31;j>=0;j--){
		ll cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i][j]==1&&(vis[i][last]==1||last==34)){
				vis[i][j]=1;
				cnt++;
			}
		}
		if(cnt>=m){last=j; ans+=(1<<j);}
	}
	cout<<ans;
	return 0;
}
