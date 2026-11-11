#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[200010],pf=1e9;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pf=min(a[i],pf);
	}cout<<pf
	return 0;
}
