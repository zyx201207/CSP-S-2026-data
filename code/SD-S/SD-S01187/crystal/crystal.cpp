#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500100;
int a[N],n,m,sum[N],ans=1;
int read(){
	int x=0;
	int f=1; 
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int qpow(int a,int b){
	int x=1;
	while(b){
		if(b&1){
			x=x*a;
		}
		a=a*a;
		b>>=1;
	}
	return x;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int st=1;
	for(int i=2;i<=n;i++){
//		int dx=a[i]-a[i-1];
		for(int j=st;j<=i;j++){
			if(a[i]*(i-j+1)-sum[i]+sum[j-1]<=m){
				st=j;
				ans=max(ans,i-j+1);
				break;
			}
		}
		//cout<<i<<" "<<st<<"\n";
	}
	cout<<ans;
	return 0;
} 
/*
5 8	
-3 -1 2 2 7
The end 
*/
