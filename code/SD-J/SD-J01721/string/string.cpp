#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+7;
int n,a[N],ans;char c[N];
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		while(a[i]--)s+=c[i];
	}string t=s;
	reverse(s.begin(),s.end());
	for(int i=0;i<s.size();i++)
		ans+=(s[i]==t[i]);
	cout<<ans<<endl;
} 
