#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500000+5],vis[500000+5],ans=-1e9;
void dfs(long long to,long long step,long long cnt){
	if(step>n){
		long long cnt0=(cnt+1)/2;
		long long cnt1=0,num,sum=0;
		for(long long i=1;i<=n;i++){
			if(vis[i]==1){
				cnt1++;
			}
			if(cnt1==cnt0){
				num=a[i];
			}
		}
		for(long long i=1;i<=n;i++){
			if(vis[i]==1){
				sum+=abs(a[i]-num);
			}
		}
		if(sum<=m){
			ans=max(ans,cnt);
		}
		return ;
	}
	vis[step]=1;
	dfs(to+a[step],step+1,cnt+1);
	vis[step]=0;
	dfs(to,step+1,cnt);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int flag1=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>3){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]) 
				flag1=0;
		}
	}
	if(flag1==1){
		long long x=a[2]-a[1];
		long long cnt=1;
		ans=1;
		if(m>x*(n-1)*n/2){
			cout<<n;
			return 0;
		}
		while(m>0&&ans<n){
			if(m>=cnt*x){
				m-=cnt*x;
				ans++;
				cnt++;
			}else{
				break;
			}
		}
		cout<<ans;
	}else{
		dfs(0,1,0);
		cout<<ans;
	}
	return 0;
}
