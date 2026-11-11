#include<bits/stdc++.h>
using namespace std;
int a[20005],vis[20005];
int n,m,ans=-1e9;
vector<int> v;
void dfs(int k){
	if(k==m+1){
		int cnt=v[0];
		cerr<<v[0]<<" ";
		for(int j=1;j<v.size();++j){
			cnt&=v[j];
			cerr<<v[j]<<' ';
			
		}
		cerr<<"\n";
		ans=max(ans,cnt);
		return;
	}
	for(int i=k;i<=n;i++){
		if(i>=k+1 && v[i]==v[i-1]) continue;
		if(!vis[a[i]]){
			vis[a[i]]=1;
			v.push_back(a[i]);
		dfs(k+1);
		v.pop_back();
		vis[a[i]]=0;
		}
		
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(n<=20){
		dfs(1);
	}
	else if(n<=2000){
		if(m==1){
			for(int i=1;i<=n;++i){
				ans=max(ans,a[i]);
			}
		}else if(m==n){
			ans=a[1];
			for(int i=2;i<=n;++i){
				ans&=a[i];
			}
		}else if(m==2){
			for(int i=1;i<=n;++i){
				for(int j=i+1;j<=n;++j){
				ans=max(ans,a[i]&a[j]);
			}
			}
		}
	}
	cout<<ans;

	return 0;
}
