#include<bits/stdc++.h>
using namespace std;
int a[2^31];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n,m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int maxn=-999999999;
	if(a[i] and a[i+1]>=maxn){
		cout<<a[i] and a[i+1];
	}
	
	}
	return 0; 
} 
