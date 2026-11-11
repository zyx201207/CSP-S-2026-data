#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int n,m,k,a[maxn],b[maxn],s[maxn],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m ;
	for(int i=1;i<=n;i++) cin >> a[i] ,b[i]=a[i];
//	sort(b+1,b+n+1);
//	k=unique(b+1,b+n+1)-b-1;
//	for(int i=1;i<=n;i++) cnt[];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		int l=1,r=i,mid;
		while(l<=r){
			mid=(l+r)/2;
			if(a[i]*(i-mid+1)-s[i]+s[mid-1]<=m) r=mid-1,ans=max(ans,i-mid+1);
			else l=mid+1;
		}
	}cout << ans ;
	return 0;
}//Crystal Peak
/*
Fly broken wings,
I know you're still with me.
All I need is a nudge to get me started.
Fly broken wings,
to somewhere we can be free.
Be closer to out ideal.
......
Fly perfect wings,
Where have you been hidden in?
Bring me to the mind that got us started.
Fly perfect wings,
show them who I can be.
For one last time if you will.
That's all.
*/