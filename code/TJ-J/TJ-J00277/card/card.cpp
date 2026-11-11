#include<bits/stdc++.h>
using namespace std;

long long a[500000],b[3000000];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]<=m){
			b[a[i]]++;
		}
	}
	for(int i=0;i<n;i++){
		cout<<b[i]<<" ";
	}	
	return 0;
} 
