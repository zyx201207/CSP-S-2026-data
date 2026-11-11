#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int maxx=2*1e5+10;
long long a[maxx],f[maxx];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int i,j,n,m;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=1;i<=30;i++){
		f[0]=f[0]*2+1;
	}
	for(i=1;i<=n;i++){
		for(j=m;j>=1;j--){
			f[j]=max(f[j],(f[j-1]&a[i]));
		}
	}
	cout<<f[m];
	return 0;
}

