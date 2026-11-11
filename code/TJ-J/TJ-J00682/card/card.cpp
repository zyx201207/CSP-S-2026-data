#include<bits/stdc++.h>
using namespace std;
bool vis[500005];
long long n,m,a[500005],cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			for(long long z=j+1;z<=n;z++){
				for(long long p=j;p<z;p++){
					if(a[z]==a[p]&&vis[p]==0){
						for(long long m=p;m<z;m++){
							vis[m]=1;
						}
					}
				}
			}
			if(vis[j]==0){
				cnt[a[j]]++;
			}
		}
		for(long long l=i;l<=n;l++){
			vis[l]=0;
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
} 
