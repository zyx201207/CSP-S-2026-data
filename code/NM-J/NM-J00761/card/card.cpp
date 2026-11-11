#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n=0,m=0;
	cin>>n>>m;
	int o=0;
	short f[200005]={};
	for(long long i=0;i<n;i++){
		int p=0;
		cin>>p;
		f[p]++;
		if(i==n-1){
			o=p;
		}
			}
	for(long long i=0;i<n;i++){
		if(f[i]!=0){
			if(i==o){
				cout<<m<<" ";
				continue;
			}
		cout<<f[i]<<" ";}
		}
	
	
	
	
	
	
	return 0;
} 
