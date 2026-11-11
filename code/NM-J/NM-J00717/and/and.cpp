#include <bits/stdc++.h>
using namespace std;
int n,m,ans,a,z;
int b[1000000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
	for (int i=0;i<n;i++) {
		cin>>b[i];
	}
	for (int i=0;i<=n-m-1;i++){
		int na=b[i];
		ans=max(ans,na);
		a=1;
		for (int j=i+a;z<=m;z++){
			na=na&b[j];
			a+=1;
		}

	}
	for (int i=0;i<n;i++){
		if (b[i]==ans)cout<<b[i+1];
	}
	return 0;
}
