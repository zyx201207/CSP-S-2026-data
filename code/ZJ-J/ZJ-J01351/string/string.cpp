#include <bits/stdc++.h>
using namespace std;
const int N=2e5+100;
long long n,s,sum=0,cnt=0,ans;
string ss,a;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;	
	ss="a";
	for(int i=1;i<=n;i++){
		cin>>s>>a;
		for(int j=1;j<=s;j++){
			cnt++;
			ss=ss+a;
		}
	}
	for(int i=(cnt>>1);i>=1;i--){
		if(ss[i]!=ss[cnt-i+1]) ans++;
	}
	cout<<ans;
	return 0;
}