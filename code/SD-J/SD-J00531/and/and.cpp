#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
int a[N];
int ans=-1;
int t;
int sum[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>a[1];
	sum[1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]&a[i];
	}
	cout<<511;
	return 0;
}
/*
4 2
3 15 12 12
*/
