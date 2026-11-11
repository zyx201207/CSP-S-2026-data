#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int N=2e5+10;
	long long a[N];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	int g=a[n];
	long long ans=2147483647;
	for(int i=n;i>=n-m+1;i--){
		ans=(ans & a[i]);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
    return 0;
}
