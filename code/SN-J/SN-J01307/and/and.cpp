#include<bits/stdc++.h>
using namespace std;
long long n,m,w;
long long b[200001],a[200001]; 
int main(){
	freopen("and.in ","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	w=a[n];
	for(int i=n-1;i>=n-m+1;i--){
		w&=a[i];
	}
	cout<<w;
	return 0;
} 
