#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=2e3+10;
LL n,m,f[N][N],a[N],mx,s;
//k means choose
// int dfs(int i,int j){
// 	if(j==0){
// 		return a[i+1];
// 	}
// 	// if(i<j)return 0;
// 	if(f[i][j]!=-1)return f[i][j];
// 	return f[i][j]=max(dfs(i-1,j-1)&a[i],dfs(i-1,j));

// }
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	// memset(f,-1,sizeof(f));
	// cout<<dfs(n,m);
	if(m==n){
		mx=a[1];
		for(int i=1;i<=n;i++){
			mx&=a[i];
		}
		cout<<mx;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++)
			mx=max(mx,a[i]);
		cout<<mx;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,a[i]&a[j]);
			}
		}
		cout<<mx;
		return 0;
	}
	for(int i=1;i<=n;i++){
		mx=max(mx,a[i]);
		f[i][1]=mx;
	}

	for(int i=1;i<=n;i++){
		for(int j=2;j<=m;j++){
			if(j<=i){
				f[i][j]=max(f[i-1][j-1]&a[i],f[i-1][j]);
			}
			else
				f[i][j]=f[i-1][j];
		}
	}
	cout<<f[n][m];
	return 0;
}