#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,mx=1;
	int sm=0;
	for(int i=2,j=1;i<=n;i++){
		sm+=((i-j)*(a[i]-a[i-1]));
		while(sm>m){
			sm-=a[i]-a[j];
			j++;
		}
		mx=max(mx,i-j+1);
	}
	cout<<mx;
	return 0;
}