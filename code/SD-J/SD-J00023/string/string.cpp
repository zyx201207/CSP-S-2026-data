#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define ll long long
char c[N];
int a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	ll sum=0;
	string s="";
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	cout<<s<<endl;
	string t=s;
	ll ans=0;
	reverse(t.begin(),t.end());
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=t[i])ans++;
	}
	cout<<ans;
	return 0;
}

