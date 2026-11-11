#include<bits/stdc++.h>
#define rep(n,l,r) for(int n=l;n<=r;n++)
#define rep0(n,r) for(int n=0;n<=r;n++)
#define rep1(n,r) for(int n=1;n<=r;n++)

#define N 500002
#define int long long

using namespace std;

//YuJellyfish@luogu
//349197938@Genshin
//everybody is welcomed!

//seems like lots of keybords cannot work well...

//plz note that u can only +1 instead of +-1, which has wasted someone 1h...
//(BEAUTIFUL WORDS)

int m,n,d1,d2;
int a[N],s[N];
int l,r,ans=1;

bool f(int l,int r){
	return a[r]*(r-l+1)-s[r]+s[l-1]<=m;
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	rep1(i,n)cin>>a[i];
	sort(a+1,a+n+1);
	rep1(i,n)s[i]=a[i]+s[i-1];
	
	l=1,r=1;
	while(r<n){
		if(f(l,r+1))r++,ans=max(ans,r-l+1);
		else l++;
		if(l>r)r=l;
	}
	cout<<ans<<'\n';
	return 0;
}