#include<bits/stdc++.h>
#define up(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define dn(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}
	return x*f;
}
int n;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	up(i,1,n,1){
		int a=read();char c=getchar();
		while(a--){
			s+=c;
		}
	}
	long long ans=0,l=s.size();
	for(long long i=0,j=l-1;i<j;i++,j--){
		if(s[i]!=s[j]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
