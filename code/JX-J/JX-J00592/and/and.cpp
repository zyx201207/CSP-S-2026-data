#include <bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
int a[200005],b[200005],c[200001][31];
int cheng=1;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int kl=1,q=-1;
cin>>n>>m;

for(int i=1;i<=n;i++){
	cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==1){cout<<a[n];return 0;}
	for(int i=n;i>=n-m+1;i--){
	
	while(a[i]!=0){
		c[i][kl]=a[i]%2;
		a[i]/=2;
		kl++;
		}q=kl;
		
		kl=1;
		if(i<=n-1){
			
		for(int p=1;p<=q;p++){

		if(c[i+1][p]==1&&c[i][p]==1)c[i][p]=1;
		else c[i][p]=0;
			}

		}
	}
	    for(int i=q-1;i>=1;i--){
			
			if(c[n-m+1][i]==1){
		for(int tiancai=1;tiancai<=i-1;tiancai++){
			
			cheng*=2;
			}	
		ans+=cheng;
		cheng=1;}
			}cout<<ans;
		
return 0;
}
