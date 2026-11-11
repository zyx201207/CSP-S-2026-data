#include<bits/stdc++.h>
using namespace std;
int n,m,a[100002];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<=m;i++){
		int p;
		cin>>p;
		a[p]++;
		ans=max(ans,a[p]);
	}
	cout<<n;
	fclose(stdin);
	fclose(stdout);
//	if(ans%57<21)cout<<ans;
//	else 
	return 0;
}