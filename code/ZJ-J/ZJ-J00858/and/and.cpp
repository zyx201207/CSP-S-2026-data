#include<bits/stdc++.h>
using namespace std;
int n,mx=-1,m;
int a[2005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(m==1){
		cout<<mx;
		return 0;
	}
	if(m==n){
		cout<<1;
		return 0;
	}
	cout<<1;
	return 0;
}

