#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[5000005];
long long q[5000005];
long long b[3000005];
long long c[3000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int k=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[a[j]]++;
			if(b[a[j]]>=2){
				q[k]=0;
				while(1){
					if(q[--k]==a[j]){
						break;
					}
					q[k]=0;
				}
			}
			q[k]=a[j];
			k++;
	
		}
		for(int j=1;j<=k;j++){
			c[q[j]]++;
		}
		for(int k=1;k<=m;k++){
			b[k]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
