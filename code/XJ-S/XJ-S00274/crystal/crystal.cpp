#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a[100005],sa;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=n;j++){
			 if(a[i]<=a[j]){
			 	sa=a[i];
			 }
		}
	}
	cout<<sa;
	return 0;
} 
