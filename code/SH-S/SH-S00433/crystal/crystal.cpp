#include<bits/stdc++.h>
using namespace std;
int a[5009],cha[5009];
int n,m;
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++) cha[i]=a[i+1]-a[i];
	for(int i=1;i<=n;i++){
		
	}
	return 0;
}
