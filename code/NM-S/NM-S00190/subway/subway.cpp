#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[10000005],k,a[1000005],t[1000005],ks,js,r,l,r1,l1,ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin >>w[i];
	}
	for(int i=1;i<=n;i++){
		cin >>k;
		for(int j=1;j<=n;j++){
			cin >>a[j]>>t[j];
			ans+=t[j];
		}
	}
	for(int i=1;i<=q;i++){
		cin >>ks>>js;
		cout <<ans+(w[ks]+w[js])<<endl;
	}
	return 0;
} 
