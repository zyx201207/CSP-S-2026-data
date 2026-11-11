#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL l,ans,n;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		string c;
		cin>>a>>c;
		for(int j=1;j<=a;j++) s+=c;
		l+=a;
	}
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
