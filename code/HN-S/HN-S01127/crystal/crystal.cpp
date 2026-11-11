#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,k=0,w=0,g=0;
	cin>>n>>m;
	int a[n];
	for(int r=0;r<n;r++){
		cin>>a[r];
		k+=a[r];
	}
	for(int u=0;u<n;u++){
		if(a[u]<=k%5&&m>w){
		for(int o=a[u];o<=k%5;o++){
			w++;
			if(o=k%5){
				g++;
			}
		}
		}
	} 
	cout<<g;
	return 0;
} 
