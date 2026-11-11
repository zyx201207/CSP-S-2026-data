#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200010];
string s[200010];
int p[30]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,
	262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,
	268435456,536870912};
void solve(){
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		for (int j=29;j>=0;j--){
			if (a[i]>=p[j]){
				a[i]-=p[j];
				s[i]=s[i]+"1";
			}else s[i]=s[i]+"0";
		}
	}
	sort(s+1,s+n+1);
	string st="";
	int ans=0;
	for (int i=0;i<30;i++){
		int cnt=0;
		for (int j=1;j<=n;j++){
			if (st<=s[j].substr(0,i)&&s[j][i]=='1') cnt++;
		}
		if (cnt>=m){
			st=st+"1";
			ans=ans*2+1;
		}else{
			st=st+"0";
			ans=ans*2;
		}
	}
	cout << ans << endl;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T=1;
//	cin >> T;
	while (T--){
		solve();
	}
	return 0;
} 
