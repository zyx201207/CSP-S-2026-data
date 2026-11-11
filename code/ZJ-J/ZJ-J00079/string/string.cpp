#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],h,t,hs,ts,ans;
char s[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>s[i];
	h=1,t=n;
	while(h<t){
		if(a[h]<=a[t]){
			if(s[h]!=s[t])ans+=a[h];
			a[t]-=a[h];h++;
		}
		else {
			if(s[h]!=s[t])ans+=a[t];
			a[h]-=a[t];t--;
		}
	}
	cout<<ans;
	return 0;
}