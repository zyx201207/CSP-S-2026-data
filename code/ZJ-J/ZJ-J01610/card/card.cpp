#include<bits/stdc++.h>
using namespace std;
const int N=5e5+2;const int M=3e5+2;
long long n,m,a[N],vis[N],ans[M];
int main(){
	freopen("card.in","r",stdin);freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=199){
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof vis);
			for(int j=i;j<=n;j++){
				for(int k=i;k<j;k++){
					if(a[k]==a[j]&&vis[k]==0){
						for(int ss=k;ss<j;ss++) vis[ss]=1;
					}
				}
			}
			for(int j=i;j<=n;j++){
				if(vis[j]==0) ans[a[j]]++;
			}
		}
	}// 4 3 1 2 1 3
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}