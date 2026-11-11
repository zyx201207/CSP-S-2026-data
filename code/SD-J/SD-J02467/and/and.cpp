#include<bits/stdc++.h>
#define int long long
using namespace std;
long long n,m;
long long a[200010],vis[200010];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=60;i>=0;i--){
		int cnt=0;
		bool flag=0;
		for(int j=1;j<=n;j++){
			if((a[j]&(1LL<<i))!=0&&vis[j]==0){
				cnt++;
			}
		}
		if(cnt>=m){
			flag=1;
			for(int j=1;j<=n;j++){
				if((a[j]&(1<<i))==0){
					vis[j]=1;
				}
			}
		}
		ans=ans*2+flag;
	}
	cout<<ans;
	return 0;
}

