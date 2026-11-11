#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m;
int a[N],vis[N],b[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int l=i,r=i;
		memset(vis,0,sizeof(vis));
		while(l<=r){
			if(a[l]==a[r]&&vis[l]==0&&vis[r]==0){
				for(int j=l;j<=r;j++){
					vis[j]=1;
				}
				l=r,r++;
			}
			else{
				r++;
			} 
			if(r==n){
				break;
			}
		}
		for(int j=i;j<=n;j++){
			if(vis[j]==0){
				b[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i];
	}
	return 0;
}
