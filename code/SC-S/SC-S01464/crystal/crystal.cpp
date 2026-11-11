#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],cf[500010],cfqzh[500010],maxn=1,len,now;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	len=1;
	for(int i=2;i<=n;i++){
		now+=(a[i]-a[i-1])*len; // 请问会不会爆 longlong？？？
		len++;
//		cerr<<i<<' '<<len<<' '<<now<<'\n';
		while(now>m){
			now-=a[i]-a[i-len+1];
			len--;
		}
		maxn=max(maxn,len);
	}
	cout<<maxn<<'\n';
	return !"I'm xcb";
}
/*
Oct31==Dec25?

这密码不对吧...

@double_bird 我喜欢你喵
@double_bird 我喜欢你喵
@double_bird 我喜欢你喵
@double_bird 我喜欢你喵
@double_bird 我喜欢你喵
@double_bird 我喜欢你喵
@double_bird 我喜欢你喵
@double_bird 我喜欢你喵
*/