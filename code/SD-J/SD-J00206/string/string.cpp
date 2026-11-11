#include<bits/stdc++.h>
using namespace std;
long long n,cnt=1,ans;
char a[2000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		char y;
		cin>>x>>y;
		for(int o=cnt;o<x+cnt;o++) a[o]=y;
		cnt+=x;
	}
	cnt--;
	for(int i=1;i<=cnt;i++) if(a[i]!=a[cnt-i+1]) ans++;
	cout<<ans/2;
	return 0;
}
