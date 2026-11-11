#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,a[N],ans=0,cnt=0;
char c[N];
bool dis[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i],cnt+=a[i];
	int l=1,r=n,lnum=a[1],rnum=a[n];
	while(1){
		if(lnum==0||rnum==0||l==r) break;
		if(dis[l]==true&&dis[r]==true) break;
		dis[l]=true,dis[r]=true;
		if(c[l]==c[r]){
			if(lnum<rnum) rnum-=lnum,lnum=a[l+1],l++;
			else if(rnum<lnum) lnum-=rnum,rnum=a[r-1],r--;
			else lnum=a[l+1],l++,rnum=a[r-1],r--;
		}
		else{
			if(lnum<rnum) ans+=lnum,rnum-=lnum,lnum=a[l+1],l++;
			else if(rnum<lnum) ans+=rnum,lnum-=rnum,rnum=a[r-1],r--;
			else ans+=lnum,lnum=a[l+1],l++,rnum=a[r-1],r--;
		}
	}
	cout<<ans;
	return 0;
}
