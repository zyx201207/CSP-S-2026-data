#include<bits/stdc++.h>

#define ll long long
#define MAXX 2000005

using namespace std;

inline ll read(){
	ll k=0,f=1;
	char c=getchar();
	while(c>'9' or c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9' and c>='0'){
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
}

inline void write(ll k){
	if(k<0)putchar('-'),k=-k;
	if(k>9)write(k/10),k%=10;
	putchar(k+'0');
}

	ll c,t,n,d,a[MAXX];


int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	
	
	c=read(),t=read();
	while(t--){
		
		ll sum=0,ok=n,ans=0;

		n=read(),d=read();
		
		if(n<2){
			write(0);
			putchar('\n');
			continue;
		}
		
		
		for(int i=1;i<=n;i++){
			a[i]=read();
			if(i==2)sum=a[i]-a[i-1];
		}
		if(sum>=d or d>=sum*3){
			write(0);
			putchar('\n');
			continue;
		}
		
		
		for(int i=1;i<n;i++){
			if(sum*i>d){
				ok=i+1;
				ans++;

				break;
			}
		}
		
		
		if(ok>=n){
			write(ans);
			putchar('\n');
			continue;
		}
		
		
		ans+=n-ok;
		write(ans);
		putchar('\n');
		
	}
	
	return 0;
}

