#include<bits/stdc++.h>

using namespace std;
long long n,m,a[500005],b[500005];
int main(){
	freopen(card.in,"r",stdin);
	freopen(card.out,"w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long i=0;i<n;i++){
		for(long long j=0;j<i;j++){
			if(b[j]==b[j]){
				for(long long x=i-j;x<i;x++){
					b[i-x]=b[x];
				}
				for(long long x=i-j;x<x;x++){
					b[x]=0;
				}
			}
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
