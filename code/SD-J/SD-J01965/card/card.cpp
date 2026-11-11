#include<bits/stdc++.h>
using namespace std;
int a[500005],sum[300005];
bool b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int o=i;o<=n;o++){
			b[o]=1;
		}
		for(int p=i;p<n;p++){
			for(int j=p+1;j<=n;j++){
				if(a[p]==a[j]&&b[p]==1&&b[j]==1){
					for(int k=p;k<j;k++){
						b[k]=0;
					}
				}
			}
		}
		for(int l=i;l<=n;l++){
			if(b[l]){
				sum[a[l]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
