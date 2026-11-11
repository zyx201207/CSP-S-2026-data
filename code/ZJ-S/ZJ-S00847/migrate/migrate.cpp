#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,ans,num;
int a[2000010];
void dfs(int r,int cnt,int p){
	if(num>2) return;
	if(cnt==0){
		if(p==r) num++;
		return ;
	}
	for(int i=p+1;i<=r;i++){
		if(a[i]-a[p]>d) break;
		dfs(r,cnt-1,i);
	}
}
signed main(){
	std::ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n==1){
			cout<<"0\n";
			continue;
		}
		if(a[n]-a[1]<=d){
			cout<<"0\n";
			continue;
		}
		int mn=1e18;
		for(int i=2;i<=n;i++) mn=min(mn,a[i]-a[i-1]);
		if(mn>=d){
			cout<<"0\n";
			continue;
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
				int k=i+1,lst=i,cnt=0,f=1;
				while(k<=j){
					if(a[k]-a[lst]>d){
						if(k==lst+1){
							f=0;
							break;
						}
						cnt++;
						lst=k-1;
					}
					else k++;
				}
				if(f==0) break;
				cnt++;
				if(cnt==j-i||cnt==1) continue;
				num=0; 
				dfs(j,cnt,i);
				if(num==2) ans++;
			}
		}
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}
