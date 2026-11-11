#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,i,t,w,st,sw,ans,a[200010];
char s[200010];
main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i]>>s[i];
	t=1;w=n;st=a[1];sw=a[n];
	while(t<w){
		ans+=min(st,sw)*(s[t]!=s[w]);
		if(st==sw){
			t++,w--;
			st=a[t];sw=a[w];
		}
		else if(st<sw){
			sw-=st;
			t++;st=a[t];
		}
		else{
			st-=sw;
			w--;sw=a[w];
		}
	}
	cout<<ans;
	return 0;
}
