#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,x;
	cin>>n>>m;
	long long a[n];
	long long ans[m+5]={};
	bool pan=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}for(long long i=0;i<n;i++){
		x=i;
		for(long long j=i;j<n;){
			pan=0;
			for(long long k=n-1;k>j;k--){
				if(a[k]==a[j]){
					pan=1;
					x=k;
					continue;
				}
			}if(pan==1){
				j=x;
			}else{
				ans[a[j]]++;
				j++;
			}
		}
	}for(long long i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
