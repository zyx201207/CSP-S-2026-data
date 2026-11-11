#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500001],fa[500001],ma,nz=1,f=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	for(int i=1;i<=m;i++){
		a[i]=ma-a[i];
	}
	sort(a+1,a+m+1);
	for(int i=1;i<=m;i++){
		fa[i]=fa[i-1]+a[i];
	}
	/*for(int i=1;i<=m;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;*/
	for(long long i=1;i<=m;i++){
		for(long long j=i;j<=m;j++){
			//cout<<i<<" "<<j<<" "<<fa[j]-fa[i-1]-(j-i+1)*a[i]<<" "<<((fa[j]-fa[i-1]-(j-i+1)*a[i])<=n)<<endl;
			if(fa[j]-fa[i-1]-(j-i+1)*a[i]<=n){
				nz=max(nz,j-i+1);
				f=0;
			}
			else{
				break;
			}
		}
		if(f){
			break;
		}
	}
	cout<<nz;
	return 0;
}
