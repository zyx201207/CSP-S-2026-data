#include <bits/stdc++.h>
using namespace std;
int const maxn = 2*100000+1000;
int a[maxn],n,m;
long long cnt;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	sort(a,a+n,greater<int>());
	cnt=a[0];
	for(int i=1;i<m;i++){
		cnt = cnt&a[i];
	}
	cout<<cnt;
	return 0;
} 
