#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;cin>>n;int m;cin>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,greater<int>());
	cout<<a[m-1];
return 0;
}
