#include<bits/stdc++.h>
#define ll long long
#define int long long
#define N 200050
#define M 1
#define rep(a,b,c) for(int a=(b);a<=(c);a++)
using namespace std;
ll n,a[N],s[N],e[N],panl[N],panr[N],ans;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ll noww=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s[i]=noww+1;
		noww=e[i]=noww+a[i];
	}
	for(int i=1;i<=n;i++){
		panl[i]=noww+1-e[i];
		panr[i]=noww+1-s[i];
	}
	ll l=1,r=n,nowl=1,nowr=noww;
	while(l<r){
		while(nowl<=e[l]){
			ll rs=max(panl[l],s[r]);
			ll re=noww+1-nowl;
			if(c[l]!=c[r])ans+=(re-rs+1);
			nowl+=(re-rs+1);
			if(rs==s[r])r--;
		}
		l++;
	}
	cout<<ans<<endl;
	return 0;
} 
//Trick||Treat!
