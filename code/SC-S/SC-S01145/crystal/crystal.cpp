#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,m;
int a[N];
int main(){
	int k=1,z=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		z+=(a[i]-a[i-1])*(i-1);
		if(z>m) break;
		k++; 
	}
	cout<<k;
	return 0;
}