#include<bits/stdc++.h>
using namespace std;
struct po{
	long long x;
	char c;
}a[200005];
long long le,ri,n,ans,l,r,sum;
string s;
int main(){ios::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		for(int j=1;j<=a[i].x;j++)s+=a[i].c;
	}
	for(int i=0;i<s.size()/2;i++)ans+=(s[i]!=s[s.size()-i-1]);
	cout<<ans;
	return 0;
}