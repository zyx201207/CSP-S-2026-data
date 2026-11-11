#include<cstdio>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
const int N=5e5+100;
const LL INF=1e18+100;
int n,ans,len,l=1;
LL m,a[N],la;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	a[n+1]=INF; la=a[1];
	for(int r=1;r<=n;r++){
		if(a[r]==a[r+1]) continue;
		if(a[l]==a[r]){
			ans=len=r-l+1;
			la=a[1]; continue;
		}
		int cnt=0,up=0,now=0;
		int op=min(m/(a[r]-la),(LL)len);
		len-=op;
		m=m-op*(a[r]-la);
		while(la>a[l]&&cnt+up<len){
			if(now+m>=a[r]-la){
				op=min((now+m)/(a[r]-la),(LL)(len-cnt-up));
				up+=op;
				if(now>=op*(a[r]-la))
					now-=op*(a[r]-la);
				else
					m-=op*(a[r]-la)-now,now=0;
			}
			if(cnt+up>=len) break;
			now+=la-a[l+cnt];
			cnt++;
		}
		m+=now;
		l=l+len-up;
		len=r-l+1;
		la=a[r];
		ans=max(ans,len);
	}
	cout<<ans<<"\n";
	return 0;
}
