#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<=c;a++)
#define dep(a,b,c) for(int a=b;a>=c;a--)
#define pi pair<int,int>
#define vi vector<int> 
#define inf 0x3f3f3f3f3f3f3f3fll
#define int long long
const int N=2e5+5,mo=1e9+7;
int n,a[N],sum=0;
char c[N];
string s=" ";
void solve(){
	cin>>n;
	rep(i,1,n){
		cin>>a[i]>>c[i];
		sum+=a[i];
		rep(j,1,a[i]) s+=c[i];
	}
	int cnt=0;
	dep(i,sum/2,1) if(s[i]!=s[sum/2*2+2-i]) cnt++;
	cout<<cnt;
	return;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}
//RP++!
