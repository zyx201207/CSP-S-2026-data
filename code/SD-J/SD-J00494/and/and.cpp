#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--)cout<<a[i]<<" ";cout<<"\n";
	cout<<a[n-m+1];
	return 0;
}
//T3经过证实，以上做法被假掉了，但是我貌似并不会写暴力，所以炸了... 
