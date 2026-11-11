#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
const int M=3e3+10;
int n,m;
int a[N];
int f[N];
int ans[M]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int x=0;
		for(int j=i;j<=n;j++){
			for(int k=x;k>=1;k--){ 
				if(f[k]==a[j]){
					for(int l=k;l<=j-1;l++){
						f[l]==0;
					}
					x=k-1;
				}
			}
			x++; 
			f[x]=a[j];
		}
		for(int j=1;j<=x;j++){
			ans[f[j]]++;
		}
		for(int j=1;j<=x;j++){
			f[j]=0;
		} 
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
} 
