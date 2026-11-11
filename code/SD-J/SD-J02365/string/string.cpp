#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,a,ans,len;
string s;
char d;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>d;
		for(int j=1;j<=a;j++){
			s+=d;
		}
		len+=a;
	}
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}

