#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=2e5+10;
struct point{
	int x;
	char c;
}a[N];
int n,ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].c;
	int lpos=1,lnum=0,rpos=n,rnum=0;
	while(lpos<rpos){
		int add=min(a[lpos].x-lnum,a[rpos].x-rnum);
		if(a[lpos].c!=a[rpos].c) ans+=add;
		lnum+=add,rnum+=add;
		if(lnum==a[lpos].x) lpos++,lnum=0;
		if(rnum==a[rpos].x) rpos--,rnum=0;
	}
	cout<<ans;
	cout<<flush;
	fclose(stdin),fclose(stdout);
	return 0;
}
