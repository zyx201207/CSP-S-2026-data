#include <bits/stdc++.h>
using namespace std;
long long n,m,ans=0,a[10005],b[10005],l=0,y=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
