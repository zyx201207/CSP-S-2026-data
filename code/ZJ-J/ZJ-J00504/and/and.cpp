#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=2e5+5;
int a[maxn][40];
bool vis[maxn];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){	
		int x,cnt=1;
		cin>>x;
		while(x){
			if(x%2==0) a[i][cnt]=0;
			else a[i][cnt]=1;
			x/=2;
			cnt++;
		}
	}
	for(int i=30;i>=1;i--){
		int res=0;
		for(int j=1;j<=n;j++){
			if(a[j][i]==1&&vis[j]==0) res++;
		}
		if(res>=m){
			for(int j=1;j<=n;j++){
				if(a[j][i]==0) vis[j]=1;
			}
			ans+=pow(2,i-1);
		}
	}
	cout<<ans;
	return 0;
}