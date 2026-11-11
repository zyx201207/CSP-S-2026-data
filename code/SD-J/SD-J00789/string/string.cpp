#include<bits/stdc++.h>
using namespace std;
int n,z[200005];
long long ans,r,g[200005],t[200005];
string p;
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>z[i]>>s[i];
		ans+=z[i];
	}
	ans/=2;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=z[i];j++){
			p+=s[i];
		}
	}
	for(int i=1;i<=ans;i++){
		if(p[i]-'a'!=p[ans+i]-'a'){
			r++;
		}
	}
	cout<<r;
	return 0;
}
