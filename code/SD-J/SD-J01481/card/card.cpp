#include<bits/stdc++.h>
using namespace std;
long long n,m,sum=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	long long a[n]={},b[m]={},c[n]={};
	for(long long i=0;i<n;i++) cin>>a[i];
	for(long long z=0;z<n;z++){
		for(long long i=z;i<n;i++){
			c[i]=a[i];
			for(long long j=z;j<i;j++){
				if(c[j]==c[i]){
					for(long long k=j;k<i;k++) c[k]=0;
					break;
				}
			}
		}
		for(long long w=1;w<=m;w++){
			for(long long e=z;e<n;e++){
				if(c[e]==w) b[w-1]++;
			}
		}
		c[n]={}; 
	}
	for(long long i=0;i<m;i++) cout<<b[i]<<" ";
	return 0; 
}
