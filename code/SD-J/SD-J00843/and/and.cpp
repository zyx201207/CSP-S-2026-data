#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	string st;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,greater<int>());
	ull ans=a[1];
	for(int j=1;j<m;j++){
		ans&=a[j];
	}
	cout<<ans;
	return 0;
}
