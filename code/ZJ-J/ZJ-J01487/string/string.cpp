#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans;
string s="";
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int p;
		char c;
		cin>>p;
		cin>>c;
		for(int j=1;j<=p;j++)s+=c;
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1])ans++;
	}
	cout<<ans;
}
/*
huanghaoxuan1117

D**n who knew.

Man f**k that s**t.

I'm in the shadow of the shadow of the sun.

Where I belong girl there's something coming on.

I'm in the shadow of the shadow of the sun.

Oh and I need you.

T2 is tooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo diffcult

When it all falls down I'll be fine.

I'll die.

*/
