#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,s;
int a[500001];
int f[500001];
int v[35];
bool ismequn;
int b[100001];
int dfs(int x,int y,int z){
	if(x>=m)return z;
	int ans=0;
	for(int i=y+1;i<=s;i++){
		if(z==0)ans=max(dfs(x+1,i,b[i]),ans);
		else ans=max(ans,dfs(x+1,i,z&b[i]));
	}
	return ans;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=31;j++){if((a[i]>>(j-1))&1){v[j]++;}}
	}
	for(int i=31;i>=1;i--){
		if(v[i]>=m){
			for(int j=1;j<=n;j++){
				if((a[j]>>(i-1))&1==1){
					b[++s]=a[j];
				}
			}
			cout<<dfs(0,0,0)<<endl;
			return 0;
		}
	}
	cout<<0<<endl;
	return 0;
}

