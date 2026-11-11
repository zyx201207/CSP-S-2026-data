#include<bits/stdc++.h>
using namespace std;
const int N=5e5,M=3e5;
int n,m,a[N],b[N],sum[M]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=i;k<=n;k++){
				for(int l=i;l<k;l++){
					if(b[k]==b[l]){
						for(int o=l+1;o<=k;o++){
							b[o]=0;
						}
					}
				}
			}
			for(int k=i;k<=n;k++){
				if(b[k]==j){
					sum[j]++;
				}
			}
		}
		for(int j=1;j<=n;j++){
			a[i]=a[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
