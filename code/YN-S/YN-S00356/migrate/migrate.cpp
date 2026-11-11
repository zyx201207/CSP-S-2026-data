#include<bits/stdc++.h>
using namespace std;
const int N=2e6+100;
int c,t,n,d,a[N],ans,cnt;
void dfs(int q,int z,int r,bool flag){
	if(q==z){
		cnt++;
		return;
	}
	if(cnt>2)return;
	if(q>z)return;
	if(flag==0){
		dfs(q+r,z,r,1);
		dfs(q+d,z,r,0);
	}
	dfs(q+d,z,r,1);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<d+1)continue;
				bool flag=0;
				for(int k=i;k<j;k++)
					if(a[k+1]-a[k]>d){
						flag=1;
						break;
					}
				if(flag==1)continue;
				cnt=0;
				if((a[j]-a[i])%d==0)continue;
				dfs(a[i],a[j],(a[j]-a[i])%d,0);
				if(cnt==2)ans++;
			}
		cout<<ans<<"\n";
	}
	return 0;
}
