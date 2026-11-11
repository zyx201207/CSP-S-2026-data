#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,m;
int a[maxn];
int zc[maxn];
bool f[maxn];
int ans[300010];
int k;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		k=1;
		for(int j=1;j<=n;j++){
			zc[j]=0;
		}
		for(int j=1;j<=m;j++){
			f[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(f[a[j]]==0){
				zc[k]=a[j];
				k++;
				f[a[j]]=1;
			}else{
				for(int o=1;o<=k-1;o++){
					if(zc[o]==a[j]){
						for(int p=o+1;p<=k-1;p++){
							f[zc[p]]=0;
							zc[p]=0;
						}
						k=o+1;
						break;
					}
				}
			}
		}
		for(int j=1;j<=k-1;j++){
			ans[zc[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

