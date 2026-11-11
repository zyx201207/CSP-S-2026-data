#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
#define F_up(x,y,z) for(int x=y;x<=z;x++)
#define F_down(x,y,z) for(int x=y;x>=z;x--)
#define F_in(x,y) for(auto x:y)
#define W(t) while(t--)
#define WALL while(1)
using namespace std;
int n,m;
int a[500005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	F_up(i,1,n){
		cin>>a[i];
	}sort(a+1,a+n+1);
	int now=0,ans=1;
	F_up(i,2,n){
		now=now+(i-1)*(a[i]-a[i-1]);
		if(now>m) break;
		ans++;
	}cout<<ans;
	return 0;
}
