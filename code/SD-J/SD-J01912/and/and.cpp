#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],b[1005][1005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==n){
		cout<<a[1];
	}if(m==1){
		cout<<a[n];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

