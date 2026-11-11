#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],c[500005],c_len;
bool clean_c(long long r){
	for(int i=r;i<=c_len;i++) c[i]=0;
	c_len=r;
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=1;k<=c_len;k++){
				if(c[k]==a[j]){
					clean_c(k);
					break;
				} 
			}
			c[++c_len]=a[j];
			if(j==n){
				for(int i=1;i<=c_len;i++) b[c[i]]++;
				clean_c(0);
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}
