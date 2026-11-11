#include <bits/stdc++.h>
#define int long long
#define ret return
#define mid (l+r>>1)
using namespace std;
int read(){
	int s=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
	ret s*f;
}
const int N=5e5+10,Mod=998244353;
int a[N];
void solve(){
	int n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	int l=1,sum=0,ans=1;
	for(int i=2;i<=n;i++){
		sum+=(i-l)*(a[i]-a[i-1]);
		while(sum>m){sum-=a[i]-a[l];l++;}
		ans=max(ans,i-l+1);
	}
	printf("%lld",ans);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int t=1;while(t--)solve();
	ret 0;
}//Oct31==Dec25?
