#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,a,cnt=0;
	char c;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++) s+=c;
	}
	int len=s.size();
	for(int i=0;i<=len/2;i++){
		if (s[i]!=s[len-1-i]) cnt++;
	}
	if (!cnt){
		cout<<0;
		return 0;
	}
	if (len%2) cout<<cnt;
	else cout<<cnt-1;
	return 0;
}

