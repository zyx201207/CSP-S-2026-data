#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=200005;
struct zxr{
	int x;
	char c;
}qzn[N];
int n,ans;
	signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>qzn[i].x>>qzn[i].c;
	}
	int l=1,r=n;
	while(l<=r){
		int minn=min(qzn[l].x,qzn[r].x);
		if(qzn[l].c!=qzn[r].c){
			ans+=minn;
		}
		qzn[l].x-=minn;
		if(!qzn[l].x){
			l++;
		}
		qzn[r].x-=minn;
		if(!qzn[r].x){
			r--;
		}
	}
	cout<<ans;
	return 0;
}
