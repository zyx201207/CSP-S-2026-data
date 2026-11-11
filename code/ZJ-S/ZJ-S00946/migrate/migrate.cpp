#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[5005],ans,mi[5005],n,k,sum,sum1;
void dfs(int st,int en){
	if(st>=en){
		if(sum==mi[en]) sum1++;
		return;
	}
	if(sum>=mi[en]) return;
	int i=st+1;
	while(a[i]-a[st]<=k&&i<=en){
		sum++;
		dfs(i,en);
		i++;
		sum--;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++) mi[j]=0;
			int st=a[i];
			for(int j=i+1;j<=n;j++){
				if(a[j]>st){
					st+=k;
					if(a[j]>st) break;
					mi[j]=mi[j-1]+1;
				}
				else mi[j]=mi[j-1];
			}
			for(int j=i+2;j<=n;j++){
				if(mi[j]<=1) continue;
				sum=0,sum1=0;
				dfs(i,j);
				if(sum1==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

