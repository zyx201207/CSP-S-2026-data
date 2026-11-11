#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,cnt=0;
	cin>>n>>m;
	long long a[n+10];
	for(long long i=0; i<n; i++){
		cin>>a[i];
	}
	long long zx=a[0];
	for(long long i=1; i<n; i++){
		zx=min(zx,a[i]);
	}
	while(m>0){
		for(long long i=0; i<n; i++){
		    if(a[i]==zx){
		    	a[i]++;
		    	m--;
			}
			zx++;
	    } 
	}
	for(long long i=0; i<n; i++){
		long long num=0;
		for(long long j=i; j<n; j++){
			 if(a[j]==a[i])    num++;
		}
	    cnt=max(cnt,num);
	}
	cout<<cnt;
	return 0;
} 
