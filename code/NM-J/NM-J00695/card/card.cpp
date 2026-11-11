#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],cnt[N],b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;j++){
			for(int k=i;k<=j;k++){
				if(a[k]==a[j]){
					for(int z=k;z<j;z++){
						a[z]=0;
					}
				}
			}
		}
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;k++){
				if(a[j]==k){
					cnt[k]++;
				}
			}
		}
		for(int j=i;j<=n;j++){
			a[j]=b[j];
		}
		for(int j=1;j<=i;j++){
			a[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
} 
