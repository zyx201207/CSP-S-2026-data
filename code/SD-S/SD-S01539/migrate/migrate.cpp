#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
int c,t,n,d,a[100005],ans,ad;
void dfs(int s,int t,int x,int da,int bj){
	if(s>=t){
		if(s==t&&da==bj){
			ad++;
		}
		return;
	}
	if(a[s]+d>=a[x+1]){
		dfs(x+1,t,x+1,da+1,bj);
		dfs(s,t,x+1,da,bj);
	}
}
void solve(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=18){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int p=a[i],cnt=0;
				ad=0;
				while(1){
					cnt++;
					if(p+d>=a[j]){
						break;
					}
					p=*lower_bound(a+1,a+1+n,p+d); 
				}
				dfs(i,j,i,0,cnt);
				if(ad==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
