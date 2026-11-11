#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[300010];
int q[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>q[i];
	}
	for(int i=1;i<=n;i++){
		bool vis[300010];
		for(int qw=1;qw<=n;qw++)vis[qw]=0;
		for(int r=i+1;r<=n;r++){
			for(int l=i;l<=r-1;l++){
				if(q[l]==q[r]&&!vis[l]){
					for(int p=l;p<=r-1;p++){
						vis[p]=1;
					} 
					break;
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(!vis[j]){
				a[q[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<a[i]<<" ";
	return 0;
}
