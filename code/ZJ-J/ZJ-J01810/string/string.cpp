#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
long long l,r,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	for(int wl=0,wr=n+1;wl<wr;){
		if(l<=r){
			wl++;
			if(c[wl]!=c[wr])ans+=min(r-l,(long long)a[wl]);
			l+=a[wl];
		}
		else{
			wr--;
			if(c[wl]!=c[wr])ans+=min(l-r,(long long)a[wr]);
			r+=a[wr];
		}
	}
	cout<<ans;
	return 0;
}