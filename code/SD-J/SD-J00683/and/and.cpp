#include<bits/stdc++.h>
using namespace std;

#define int long long 
const int N=3e5+5;
int n,m;
int a[N];
bitset<35> b[N];
bool c[N];
int ans;

inline int read(){
	int f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		int t=a[i];
		for(int j=0;j<=30;j++){
			b[i][j]=t&1;
			t>>=1;
		}
	}
	for(int j=30;j>=0;j--){
		int res=0;
		 for(int i=1;i<=n;i++){
		 	if(!c[i] && b[i][j])++res;
		 }
		 if(res>=m){
		 	ans|=(1ll<<j);
		 	for(int i=1;i<=n;i++){
		 		if(!b[i][j])c[i]=1;
			 }
		 }
	}
	cout<<ans<<endl;
	return 0;
} 
