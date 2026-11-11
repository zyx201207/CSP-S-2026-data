#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
inline int read(){
	int f=1,x=0;char ch=getchar();
	while('0'>ch||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
int c,T;
int n,d;
int x[N],dp[N];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),T=read();
	while(T--){
		int head=1;
		n=read(),d=read(),x[1]=read();
		for(int i=2;i<=n;i++){
			x[i]=read();
			if(x[i]-x[i-1]>d) head=i;
			
		}
		
	}
	return 0;
}
