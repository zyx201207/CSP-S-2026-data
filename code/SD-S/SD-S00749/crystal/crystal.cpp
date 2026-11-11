#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	char c=getchar();
	long long x=0,f=1;
	while(c>'9'||c<'0'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
inline void write(long long x){
	if(x<0){
		putchar('-');
		write(-x);
		return ;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+'0');
	return ;
}
const int N=5e5+5;
int n,line,ans;
long long a[N],m;
long long s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	line=1;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		while(a[i]*(long long)(i-line+1)-(s[i]-s[line-1])>m){
			line++;
		}
		ans=max(ans,i-line+1);
	} 
	cout<<ans;
	return 0;
} 
