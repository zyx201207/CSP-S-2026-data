#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int n,m,a[500010],b[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		bool f[n+10];
		for(int j=i;j<=n;j++) f[j]=1;
		for(int j=i;j<=n;j++){
			for(int l=j-1;l>=i;l--){
				if(a[j]==a[l]&&f[l]==1){
					for(int k=l;k<j;k++) f[k]=0;
					break;
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(f[j]==1){
				b[a[j]++];
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<' ';
	return 0;
} 
