#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int a[N],vis[N],b[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	int sum=0;
	for(int j=31;j>=0;j--){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			if(a[i]>=pow(2,j)){
				ans++;
			}
		}
		if(ans>=m){
			for(int i=1;i<=n;i++){
				if(vis[i]) continue;
				if(a[i]>=pow(2,j)){
					a[i]-=pow(2,j);
				}else{
					vis[i]=1;
				}
			}
			sum+=pow(2,j);
		}
		for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			if(a[i]>=pow(2,j)){
				a[i]-=pow(2,j);
			}
		}
	}
	cout<<sum;
	return 0;
}
//262142 262143
//262144 524288 
