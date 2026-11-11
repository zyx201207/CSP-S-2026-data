#include<bits/stdc++.h>
using namespace std;
int n,m;
int mun=1;
int a[1000005];
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i+1]-a[i]<m){
			mun++;
		}
		if(a[i+2]-a[i]<m){
			mun++;
		}
	} 
	cout<<mun;
	
	return 0;
}
