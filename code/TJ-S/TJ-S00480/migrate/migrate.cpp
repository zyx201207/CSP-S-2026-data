#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
    int c,t,n,d;
    cin>>c>>t>>n>>d;
    int a[n];
    for(int i=0;i<=n;i++){
    	cin>>a[i];
	}
	int q=n-n+1;
	int b=n-n+2;
	cout<<a[q]<<"\n";
	cout<<a[b];
	return 0;
}
