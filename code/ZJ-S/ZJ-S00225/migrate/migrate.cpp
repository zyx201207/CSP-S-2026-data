#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[2000005],k,cnt;
int solve(int x,int y){
	int l=x,cnt=0;
	while(l!=y){
		cnt++;
		int flag=0;
		for(int i=y;i>l;i--){
			if(a[i]-a[l]<=d){
				l=i;
				flag=1;
				break;
			}
		}
		if(!flag) return -1;
	}
	return cnt;
}
void dfs(int x,int y,int sum){
	if(x==y){
		cnt++;
		return;
	}
	if(sum>=k) return;
	for(int i=y;i>x;i--){
		if(a[i]-a[x]<=d){
			for(int j=i;j>=max(x+1,i-2);j--) dfs(j,y,sum+1);
			break;
		}
	}
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
				k=solve(i,j);
				if(k==-1) break;
				cnt=0;
				dfs(i,j,0);
				if(cnt==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
