#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
inline void write(int k){
	if(k<10)putchar(k+'0');
	else write(k/10),putchar(k%10+'0');
}
int n,m,a[500005];
signed main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	int p=1;
 	int use=0;
	int ans=1;
	int cnt=1;
	for(int i=2;i<=n;i++){
		cnt++;
		use+=(a[i]-a[i-1])*(i-p);
		while(use>m){
			use-=(a[i]-a[p]);p++;cnt--;
		}
		ans=max(ans,cnt);
	}
	write(ans);
	putchar('\n');
	return 0;
}
