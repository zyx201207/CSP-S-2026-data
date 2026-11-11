#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[200005];
char c[200005];
string s;
int len;
int ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	for(int i=0;i<len;i++){
		if(s[i]!=s[len-1-i]){
			ans++;
			s[len-1-i]=s[i];
		}
	}
	cout<<ans;
	return 0;
}
