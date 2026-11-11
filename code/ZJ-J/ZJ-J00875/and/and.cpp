#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,cnt,ans,a[200005],vis[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=30;i>=0;i--){
		cnt=0;
		for(int j=1;j<=n;j++){
			if(vis[j])continue;
			if((a[j]&(1<<i))!=0)cnt++;
		}
		if(cnt>=m){
			ans+=(1<<i);
			for(int j=1;j<=n;j++){
			    if((a[j]&(1<<i))==0)vis[j]=1;
		    }
		}
	}
	cout<<ans;
	return 0;
}
