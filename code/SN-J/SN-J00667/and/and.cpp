//赵晗羽 西安辅轮中学  SN-J00667 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005]; 
int s=1;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1)cout<<a[n];
	else if(m==2)cout<<a[n] & a[n-1];
	else cout<<a[n] & a[n-m+1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
