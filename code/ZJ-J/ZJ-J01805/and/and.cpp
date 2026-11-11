#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long aa[200005][35],tt[35],ans,key[200005],zby;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
	for(int i=1;i<=n;i++){
		long long ls;
		cin>>ls;
		long long ws=1;
		while(ls>0){
			aa[i][ws]=ls%2;
			tt[ws]=tt[ws]+aa[i][ws];
			ws++;
			ls=ls/2;
		}
	}
	for(int i=32;i>0;i--){
		if(tt[i]>=m){
			zby=1;
			for(int j=i;j>1;j--){
				zby=zby*2;
			}
			ans=ans+zby;
			for(int j=1;j<=n;j++){
				if(key[j]){
					continue;
				}
				if(aa[j][i]==0){
					key[j]=1;
					for(int k=i-1;k>0;k--){
						tt[k]=tt[k]-aa[j][k];
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
