#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200010],t,w,i,ans=0;
char s[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i]>>s[i];
	t=1;w=n;
	while(t<=w){
		if(a[t]>a[w]){
			if(s[t]==s[w]) ;
			else ans+=a[w];
			a[t]-=a[w];
			w--;
		}
		else if(a[t]==a[w]){
			if(s[t]==s[w]) ;
			else ans+=a[t];
			t++;
			w--;
		}
		else{
			if(s[t]==s[w]) ;
			else ans+=a[t];
			a[w]-=a[t];
			t++;
		}
	}
	cout<<ans;
	return 0;
}

