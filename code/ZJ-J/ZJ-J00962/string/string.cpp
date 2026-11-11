#include<bits/stdc++.h>
using namespace std;
#define file(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define int ll
#define ll long long
#define rad read<int>
#define gc getchar
template<typename T>T read(){
	T ret=0;bool f=0;char ch;
	for(;!isdigit(ch=gc());f=!f?(ch=='-'):f);
	for(;isdigit(ch);ch=gc())ret=(ret<<3)+(ret<<1)+(ch^48);
	return f?-ret:ret;
}
#define maxn 200005
int n,a[maxn],ans;
char c[maxn];
signed main(){
	file(string);
	n=rad();
	for(int i=1;i<=n;i++)a[i]=rad(),c[i]=gc();
	int i=1,j=n;
	for(;i<j;){
		if(a[i]>a[j]&&c[i]!=c[j]){ans+=a[j],a[i]-=a[j--];continue;}
		if(a[i]>a[j]&&c[i]==c[j]){a[i]-=a[j--];continue;}
		if(a[i]==a[j]&&c[i]!=c[j]){ans+=a[i++],j--;continue;}
		if(a[i]==a[j]&&c[i]==c[j]){i++,j--;continue;}
		if(a[i]<a[j]&&c[i]!=c[j]){ans+=a[i],a[j]-=a[i++];continue;}
		if(a[i]<a[j]&&c[i]==c[j]){a[j]-=a[i++];}
//		printf("%lld %lld %lld %lld %lld\n",i,j,a[i],a[j],ans);
//		printf("%c %c\n",c[i],c[j]);
	}
	printf("%lld",ans);
	return 0;
}
