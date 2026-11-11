#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,a[N],ans,sz,now,now1;
char c[N],s[20000009];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		sz+=a[i];
	}
	now1=a[0];
	for(int i=0;i<sz;i++){
		if(now1<i) now1+=a[++now];
		s[i]=c[now];
	}
	for(int i=0;i<sz/2;i++){
		if(s[i]!=s[sz-1-i]) ans++;
	}
	cout<<ans;
	return 0;
}
