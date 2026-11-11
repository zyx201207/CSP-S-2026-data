#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int maxn=2e6+10;
ll a[maxn],c,t,n,flag[maxn],d,ans,res;
int minn;
void dfs(int step,int s,int ed){
	if(step==ed){
		if(s==minn)ans++;
		return;
	}
	for(int i=step+1;i<=n;i++){
		if(a[i]-a[step]<=d)dfs(i,s+1,ed);
		else break;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","r",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		memset(a,0,sizeof(a));
		res=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int lst=i;
				ans=minn=0;
				for(int k=i;k<=j;k++){
					if(k>i&&a[k]-a[lst]>d&&a[k-1]-a[lst]<=d){
						lst=k-1;
						minn++;
					}
				}
				dfs(i,0,j);
				if(ans==2){
					res++;
				}
			}
		}
		cout<<res<<'\n';
	}
}