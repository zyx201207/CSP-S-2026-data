#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],f[200001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	memset(f,0,sizeof(0)); 
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			m=max(a[i],m);
		}
		cout<<m;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			f[i]=max(a[i]&a[j],f[i]);
		}
	}
	cout<<f[n];
	return 0;
}
