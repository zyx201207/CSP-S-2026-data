#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+1;
int n,a[N],l=1,r,ans;
char c[N];
string s;
signed main(){
	freopen("string.in","r",stdin),freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++) s+=c[i];
	}
	for(int i=0;i<s.size();i++)
		if(s[i]!=s[s.size()-i-1]) ans++;
	cout<<ans/2;
}
