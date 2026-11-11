#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	} 
	if(m==n){
		cout<<min(a[n],a[n+1]);
	}
	                                                                      
	return 0;
} 
