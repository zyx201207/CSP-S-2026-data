#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt1=1,a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]+1){
			cnt1=0;
		}
	}
	if(cnt1==1){
		
	}else {
		for(int j=1;j<=m;j++){
			long long t[500005];
			for(int i=1;i<=n;i++){
				if(t[a[i]]==0){
					t[a[i]]=i;
				}else {
					for(int k=t[a[i]]+1;k<=i;k++){
						t[k]=0;
					}
				}
			}
			for(int z=1;z<=n;z++){
				if(t[z]!=0){
					cout<<t[z]<<' ';
				}
			} 
		}
	}
	return 0;
} 
