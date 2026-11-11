#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],vis[200010],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=31;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(vis[j])continue;
			if((a[j]>>i))cnt++;
		}
		if(cnt>=m){
			ans+=(1<<i);
			for(int j=1;j<=n;j++){
				if(vis[j])continue;
				if(!(a[j]>>i))vis[j]=1;
			}
		}
		for(int j=1;j<=n;j++){
			if(vis[j])continue;
			if((a[j]>>i))a[j]-=(1<<i);
		}
	}
	cout<<ans;
	return 0;
}
