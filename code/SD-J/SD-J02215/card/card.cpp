#include<iostream>
using namespace std;
int n,m;
int a[500005];
int cnt[300005],vis[300005];
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
	int ver;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			vis[a[j]]=0;
		}
		for(int j=i;j<=n;j++){
			cnt[a[j]]++;
			for(int k=i;k<j;k++){
				if(a[k]==a[j]){
					for(int r=i;r<j;r++){
						if(vis[r]==1){
							ver=r;
						}
					}
					for(int l=ver;l<j;l++){
						cnt[a[l]]--;
						vis[a[l]]=1;
					}
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
} 
