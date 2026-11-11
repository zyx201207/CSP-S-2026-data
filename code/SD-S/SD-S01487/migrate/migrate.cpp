#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,T,n,d;
int a[N],mx,now,cnt,ans;
void dfs(int s,int e){
	if(s==e){
		if(now<mx){
			mx=now;
			cnt=1;
		}else{
			cnt++;
		}
		return ;
	}
	for(int i=s+1;i<=e;i++){
		if(a[i]-a[s]<=d){
			now++;
			dfs(i,e);
			now--;
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>T;
	while(T--){
		int h=1,cha=0;
		mx=N,cnt=0,now=0,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=3;i<=n;i++){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
				h=0;
				break;
			}
			cha=a[i]-a[i-1];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mx=N,cnt=0,now=0;
				dfs(i,j);
				if(cnt==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

