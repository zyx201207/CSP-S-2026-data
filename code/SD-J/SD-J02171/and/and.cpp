#include<bits/stdc++.h>
using namespace std;
int n,m,a[200020],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ans=a[n];
	for(int i=m-1;i>0;i++){
		cout<<a[n-1]<<"\n";
		ans=ans&a[n-1];
		cout<<a[n-1]<<"\n";
		n--;
	}
	cout<<ans;
	return 0;
}
