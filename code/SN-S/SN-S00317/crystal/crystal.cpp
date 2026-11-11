#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int Maxn=5e5+5;
int n,m,c[Maxn],l,r,Mid,s[Maxn],ans;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>c[i];
	}
	stable_sort(c+1,c+1+n);
	for(int i=1; i<=n; i++){
		s[i]=s[i-1]+c[i];
		l=0;
		r=i-1;
		while(l<=r){
			Mid=(l+r)/2;
			if((i-Mid)*c[i]-(s[i]-s[Mid])<=m)r=Mid-1;
			else l=Mid+1;
		}
		r++;
		ans=max(ans,i-r);
	}
	cout<<ans;
	return 0;
}
/*
longlong

¶þ·Ö 
*/
