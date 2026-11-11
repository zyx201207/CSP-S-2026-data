#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],ma;
void dfs(int x,int sum,int cnt){
	if(sum>m) return;
	if(x==n+1){
		if(sum!=m) return;
		ma=max(ma,cnt);
		return;
	}
	dfs(x+1,sum+1,(sum==0?a[x]:(cnt&a[x])));
	dfs(x+1,sum,cnt);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20){
		dfs(1,0,0);
		cout<<ma;
	}
	else if(n<=2000){
		if(m==1){
			for(int i=1;i<=n;i++){
				ma=max(ma,a[i]);
			} 
		}
		else if(m==n){
			for(int i=1;i<=n;i++){
				ma=(i==1?a[1]:(ma&a[i]));
			}
		}
		else{
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					ma=max(ma,(a[i]&a[j]));
				}
			}
		}
		cout<<ma;
	}
	else{
		if(m==n-1){
			vector<int>sum1(n+1,0),sum2(n+1,0);
			sum1[1]=a[1];
			for(int i=2;i<=n;i++){
				sum1[i]=(sum1[i-1]&a[i]);
			}
			sum2[n]=a[n];
			for(int i=n-1;i>=1;i--){
				sum2[i]=(sum2[i+1]&a[i]);
			}
			ma=max(ma,max(sum1[n-1],sum2[2]));
			for(int i=2;i<n;i++){
				ma=max(ma,(sum1[i-1]&sum2[i+1]));
			}
			cout<<ma;
		}
		else{
			sort(a+1,a+n+1);
			cout<<a[n-m+1];
		}
	}
	return 0;
}
