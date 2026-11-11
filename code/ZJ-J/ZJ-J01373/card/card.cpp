#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],x[500005],sum[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x[i]=a[i];
	}
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++) x[i]=0;
		for(int i=k;i<=n;i++){
			x[i]=a[i];
		}
		for(int i=k;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(x[j]==x[i]&&x[i]!=0){
					for(int s=j;s<=i-1;s++){
						x[s]=0;
					}
				}
			}
		}
		for(int i=k;i<=n;i++){
			if(x[i]!=0){
				sum[x[i]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i];
		if(i!=m) cout<<' ';
	}
	return 0;
}
