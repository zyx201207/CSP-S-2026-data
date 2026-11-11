#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
const int N=2e5+5,MAX=1e18,MIN=-1e18;
int a[N];
char c[N];
int ans;
int sum;
int l[N],r[N];
void solve(){
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
		sum+=a[i];
	}
	int l=0,r=sum-1;
	while(l<=r){
		if(s[l]!=s[r]){
			ans++;
			l++;
			r--;
		}else{
			l++;
		}
	}
	cout<<ans;
}
signed main(){
	IOS
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T=1;//cin>>T;
	while(T--) solve();
	return 0;
}
//T2
