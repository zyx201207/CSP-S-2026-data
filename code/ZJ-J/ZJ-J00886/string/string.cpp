#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxa=200005;
LL n,a[maxa],l,r,lid,rid,ans;
char c[maxa];
LL read(){
	LL ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)) ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		cin>>c[i];
	}
	l=1,r=n;lid=a[1],rid=a[n];
	while(l<r){
		if(lid<rid){
			if(c[l]!=c[r]) ans+=lid;
			rid-=lid;l++,lid=a[l];
		}else if(lid==rid){
			if(c[l]!=c[r]) ans+=lid;
			r--,l++,lid=a[l],rid=a[r];
		}else{
			if(c[l]!=c[r]) ans+=rid;
			lid-=rid,r--;rid=a[r];
		}
	}
	printf("%lld\n",ans);
	return 0;
} 
/*
5
1 a
3 b
2 c
4 d
6 e

3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/
