#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
typedef long long ll;
ll n,m,a[200005],vis[5005][5005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[i][a[j]]){
				for(int k=vis[i][a[j]];k<j;k++){
					vis[i][a[k]]=0;
				}
				vis[i][a[j]]=j;
			}
			else{
				vis[i][a[j]]=j;
			}
		}
	}
	for(int i=1;i<=m;i++){
		ll cnt=0;
		for(int j=1;j<=n;j++){
			if(vis[j][i]){
				cnt++;
			}
		}
		cout<<cnt<<" ";
	}
	return 0;
}
