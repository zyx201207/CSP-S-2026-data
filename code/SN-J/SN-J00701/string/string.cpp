//ÃÏ³ş³Ì  ¸¨ÂÖÖĞÑ§  SN-J00701 
#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=2e5+5;
int n,a[maxn],ans,len;char c[maxn];string s;
signed main(){
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;s='p';
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];len+=a[i];
		for(int j=1;j<=a[i];j++) s=s+c[i];
	}
	for(int i=1;i<=len/2;i++) if(s[i]!=s[len+1-i]) ans++;cout<<ans<<'\n';
	//aabbc
	return 0;
}
