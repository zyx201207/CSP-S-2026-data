#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans=0,n,l,r;
int a[200005];
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		string b;
		cin>>a[i]>>b;
		for(int j=1;j<=a[i];j++){
			s=s+b;
		}
	}
	l=0,r=s.size()-1;
	while(l<r){
		if(s[l]!=s[r])ans++;
		l++,r--;
	}
	cout<<ans;
	return 0;
}
