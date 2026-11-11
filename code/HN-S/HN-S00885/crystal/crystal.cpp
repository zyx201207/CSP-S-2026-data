#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	int n,m,a[500000],sum;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	for(int i=n;i>0;i--){
		if(a[i-1]*i-sum<=m){
			cout<<i;
			return 0;
		}
	}
	
	return 0;
}
