#include<bits/stdc++.h>
using namespace std;
long long a[500100],n,m,x=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];	
	}
	sort(a,a+n);	
	while(m>0){
		for(long long i=x;i<n;i++){
			if(a[i]==a[i+1]){
				x++;
			}
			if(a[i]<a[i+1]){
				break;	
			}
		}
		if(m<x) {
		break;
		}
		for(long long i=0;i<=x;i++){
			a[i]++;	
			m--;
		}
	}
	for(long long i=0;i<n;i++){
		if(a[i]!=a[i+1]){
		cout<<i+1;
		return 0;
		}
	}
}

