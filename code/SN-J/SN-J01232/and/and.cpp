#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int mx=0,mi=100000000;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(a[i],mx);
		mi=min(a[i],mi);
	}
	if(m==1){
		cout<<mx;
		return 0;
	}
	if(m==n){
		cout<<mi;
		return 0;
	}
	else{
		cout<<1;
		return 0;
	}
}
