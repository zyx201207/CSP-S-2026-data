#include<bits/stdc++.h>
using namespace std;
long long n,m,x;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	long long a[n],b[m]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<=n;j++){
			if(a[j-i]+1==a[j-i+1]){
				x=j+1;
			}
		}
		for(int k=1;k<=x;k++){
			if(a[k]==i){
				b[i]+=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
} 
