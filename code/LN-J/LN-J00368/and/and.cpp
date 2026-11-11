#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
long long a[N];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,greater<int>());
	long long ans = a[0];
	for(int i=1;i<m;i++){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
