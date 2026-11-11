#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+2]={};
	int b[m+2]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int ab[m+2]={}; 
		for(int j=i;j<=n;j++){
			ab[a[j]]++;
			if(ab[a[j]]==2){
				int o=m;
				while(o--) ab[o]=0;
				ab[a[j]]=1;
			}
		}
		for(int r=1;r<=m;r++) b[r]+=ab[r];
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<' ';
	return 0;
} 
