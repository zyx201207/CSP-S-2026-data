#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],tong[300005],b[500005],k=1,f[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(f,0,sizeof(f));
		memset(b,0,sizeof(b));
		k=1;
		for(int j=i;j<=n;j++){
			if(f[a[j]]==0){
				f[a[j]]=k;
				b[k]=a[j];
				k++;
			}
			if(f[a[j]]!=0){
				for(int l=f[a[j]];l<=k;l++){
					b[l]=0;
				}
				b[f[a[j]]]=a[j];
				k=f[a[j]]+1;
			}
		}
		for(int j=1;j<=k-1;j++){
			tong[b[j]]++;
		}
	}
	for(int i=1;i<=300005;i++){
		if(tong[i]>0){
			cout<<tong[i]<<" ";
		}
	}
	return 0;
}