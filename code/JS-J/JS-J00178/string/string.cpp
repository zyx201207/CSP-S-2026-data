#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,num,ans;
string s;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1,a;i<=n;i++){
		char c;
		cin>>a>>c;
		for(int j=0;j<a;j++) s+=c;
		num+=a;
	}
	int l=num/2-1,r=num/2;
	if(num%2==1) l=r;
	for(;r<num;l--,r++){
		if(s[l]!=s[r]) ans++;
	}
	cout<<ans;
	return 0;
}
