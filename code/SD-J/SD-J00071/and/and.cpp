#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long a[N];
long long ans;     
long long sum1[N],sum2[N];
void dfs(int idx,int ud,long long now){
	if(ud==m){
		ans=max(ans,now);
		return;
	}
	if(idx+1<=n){
		dfs(idx+1,ud,now);
		if(now==-1){
			dfs(idx+1,ud+1,a[idx]);
		}
		else{
			dfs(idx+1,ud+1,now&a[idx]);
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}  
	if(m==1){
		long long maxx=0;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	else if(m==n){
		for(int i=1;i<=n;i++){
			if(i==1){
				ans=a[i];
			}
			else{
				ans&=a[i];
			}
		}
		cout<<ans;
		return 0;
	}
	else if(m==n-1){
		sum1[1]=a[1];
		for(int i=2;i<=n;i++){
			sum1[i]=sum1[i-1]&a[i];
		}
		sum2[n]=a[n];
		for(int i=n-1;i>=1;i--){
			sum2[i]=sum2[i+1]&a[i];
		}
		for(int i=1;i<=n;i++){
			ans=max(ans,sum1[i-1]&sum2[i+1]);
		}
		cout<<ans;
		return 0;
	}
	else{
		dfs(1,0,-1);
		cout<<ans;
	} 
	return 0;
}

