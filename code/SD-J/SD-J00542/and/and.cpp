#include<bits/stdc++.h>
using namespace std;
int a[10000],n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	memset(a,-1,sizeof(a));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
	}
	return 0;
}
