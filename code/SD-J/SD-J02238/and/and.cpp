#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[201010];
int k=0;
int f(int m){
	k++;
	if(m==1){
		return a[n-k+1];
	}
	return f(m-1)&(a[n-k+1]); 
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cout<<f(m);
	return 0;
}
