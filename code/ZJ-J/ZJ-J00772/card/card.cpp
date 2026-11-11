#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int n,m;
int a[MAXN];
int vis[MAXN];
int ans[MAXN];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			vis[a[j]]=true;
		}
		for(int j=i;j<=n;j++){
			vis[a[j]]=true;	
			for(int k=i;k<j;k++){	
				if(vis[a[k]]==true && a[k]==a[j]){
					for(int s=k;s<j;s++){
						vis[a[s]]=false;
					}
					break;
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(vis[j]==true){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}