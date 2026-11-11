#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,x,m,a[210000],ans;
void dfs(int p,int k,int mx){
	if(k==m){
		ans=max(ans,mx);
	}
	if(k>m)return;
	if(p>n)return;
	dfs(p+1,k+1,mx&a[p]);
	dfs(p+1,k,mx);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=max(ans,a[i]);
		}	
		cout<<ans<<endl;
	}
	else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans^=a[i];
		}	
		cout<<ans<<endl;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					ans=max(ans,a[i]&a[j]);
				}
			}
		}	
		cout<<ans<<endl;
	}else if(m==n-1){
		for(int i=1;i<=n;i++){
			int s=0x3f3f3f3f;
			for(int j=1;j<=n;j++){
				if(j!=i)s=s&a[j]; 
			}
			ans=max(ans,s);
		}
		cout<<ans<<endl;
	} 
	else{
		dfs(1,0,0x3f3f3f3f);
		cout<<ans<<endl;
	}
	
	return 0;
}

