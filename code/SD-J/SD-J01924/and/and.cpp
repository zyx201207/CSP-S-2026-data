#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010];
long long ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int l=0,r=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		r=max(r,a[i]);
	}
	sort(a+1,a+n+1,greater<int>());
	ans=a[1];
	for(long long i=2;i<=m;i++){
		ans&=a[i];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
