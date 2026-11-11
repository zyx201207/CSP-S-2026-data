#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],b[500005],pz[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	int x=1;
	for(long long i=1;i<=n;i++){
		int xb=0;
		for(long long j=x;j<=n;j++){
			pz[++xb]=a[j];
			for(long long k=1;k<xb;k++){
				if(a[j]==pz[k]){
					xb-=(j-k);
				}
			}
		}
		for(long long j=1;j<=xb;j++){
			b[pz[j]]++;
		}
		x++;
	}
	for(long long i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 
