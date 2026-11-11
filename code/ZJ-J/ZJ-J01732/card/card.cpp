#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],sum[N],b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			b[j]=a[j];
		}
		for(int j=i;j<=n;j++){
			for(int k=j-1;k>=i;k--){
				if(b[j]==b[k]){
					for(int l=k;l<=j-1;l++){
						b[l]=0;
					}
					break;
				}
			}
		}
		for(int j=1;j<=m;j++){
			for(int k=i;k<=n;k++){
				if(b[k]==j){
					sum[j]++;
					break;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}