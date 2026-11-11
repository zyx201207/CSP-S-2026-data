#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200010],vis[200010],ans,p[32];
string s[200010];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	p[0]=1;
	for(int i=1;i<=31;i++) p[i]=p[i-1]*2;
	for(int i=1;i<=n;i++){
		int t=a[i],v[32],l=0;
		while(t){
			v[++l]=(t&1);
			t>>=1;
		}
		int x=31-l;
		for(int j=1;j<=x;j++) s[i]=s[i]+'0';
		for(int j=l;j>=1;j--) s[i]=s[i]+char(v[j]+'0');
	}
	for(int i=0;i<31;i++){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(vis[j]) continue;
			cnt+=(s[j][i]=='1');
		}
		if(cnt>=m){
			for(int j=1;j<=n;j++){
				if(vis[j]) continue;
				if(s[j][i]=='0') vis[j]=1;
			}
			ans+=p[31-i-1];
		}
	}
	cout<<ans;
	return 0;
}
