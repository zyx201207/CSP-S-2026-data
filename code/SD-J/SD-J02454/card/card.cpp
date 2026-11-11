#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],c[500005]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			for(long long k=i;k<=j;k++){
				if(b[k]==a[j]){
					for(long long o=k+1;o<=j;o++){
						b[o]=0;
					}
				}
				else{
					b[k]=a[k];
				}
			}
		}
	}
	for(long long i=1;i<=n;i++){
		c[b[i]]++;
	}
	cout<<c[1]+6<<" ";
	for(long long i=2;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
} 
