#include<bits/stdc++.h>
#define int long long
using namespace std;
char b[200005];
int a[200005];
int c[200005];
int ans;
string s="";
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		while(a[i]--)s+=b[i];
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
