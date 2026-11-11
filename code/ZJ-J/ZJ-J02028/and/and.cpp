#include<bits/stdc++.h>
using namespace std;	
long long n,m,ma=0,ans=0,now=0;
long long dp[200010],a[200010];
bool bj[200010];
void dfs(long long x,long long sz){	
	if(x==0){
		ans=max(sz,ans);	
		return;	
	}
	for(int i=1;i<=n;i++){
		if(bj[i]==0){
			bj[i]=1;
			dfs(x-1,sz&a[i]);
			bj[i]=0;
		}
	}
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(a[i],ans);
		}
		cout<<ans;
		return 0;
	} else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					ma=a[i]&a[j];
					ans=max(ma,ans);
				}
			}
			
		}
		cout<<ans;
		return 0;
	} else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	} else if(m==n-1){
		for(int i=1;i<=n;i++){
		ma=a[i];			
			for(int j=1;j<=n;j++){
				if(j!=(i+1)%n)							
					ma=ma&a[j];			
			}
		ans=max(ma,ans);	
		}
		cout<<ans;
		return 0;
	} else {
	for(int i=1;i<=n;i++){
		bj[i]=1;
		dfs(m-1,a[i]);
		bj[i]=0;
	}
	cout<<ans;
}
	return 0;
}