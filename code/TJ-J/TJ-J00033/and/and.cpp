#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
const int N=2e5+7;
int n,m,a[N],vis[N],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=30;k>=0;k--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(vis[i]==1)continue;
			if((a[i]&(1<<k))==(1<<k))cnt++;
		}
		if(cnt>=m){
			ans=(ans|(1<<k));
			for(int i=1;i<=n;i++){
				if(vis[i]==1)continue;
				if((a[i]&(1<<k))!=(1<<k))vis[i]=1;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
