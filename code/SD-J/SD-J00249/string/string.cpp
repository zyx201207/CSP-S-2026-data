#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,ans=0;
	cin>>n;
	string s;
	for (int i=1;i<=n;i++){
		int a;string c;
		cin>>a>>c;
		for (int j=1;j<=a;j++) s+=c;
	}
	int len=s.size()/2;
	for (int i=0,j=s.size()-1;i<len,j>len;i++,j--){
		if(s[i]!=s[j]) ans++;
	}
	cout<<ans;
	return 0;
}

