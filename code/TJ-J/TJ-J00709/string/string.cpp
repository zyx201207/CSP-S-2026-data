#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,cnt;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++) s+=c;
	}
	int t=s.size();
	for(int i=0;i<=t/2;i++){
		if(s[i]!=s[t-i-1]) cnt++;
	}
	cout<<cnt;
	return 0;
}

