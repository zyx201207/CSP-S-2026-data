#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pii pair<int,int>
#define lowbit(x) ((x)&-(x))
using namespace std;
const int N=5e5;
int n,m,_,a[N+5],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1,j=1;i<=n;i++){
		_+=(i-j)*(a[i]-a[i-1]);
		while(_>m){
			_-=a[i]-a[j];
			j++;
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
