#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
const int N=2e5+5;
int n;
long long ans;
int a[N];
char c[N];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d %c",&a[i],&c[i]),getchar();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++) s+=c[i];
	}
	long long len=s.size();
	for(int i=0;i*2<len;i++){
		if(s[i]!=s[len-i-1]) ans++;
	}
	printf("%lld",ans);
	return 0;
}
