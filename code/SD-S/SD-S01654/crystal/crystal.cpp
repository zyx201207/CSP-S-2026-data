#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long a[N],maxn;
unsigned long long b[N],c[N],ans[N];
inline long long read(){
	char x=getchar();
	long long f=1,ans=0;
	while(x<'0'||x>'9'){
		if(x=='-')
			f=-1;
		x=getchar();
	}
	while(x<='9'&&x>='0'){
		ans=ans*10+x-'0';
		x=getchar();
	}
	return ans*f;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n=read(),m=read();
	for(long long i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+n+1);
	for(long long i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
		c[i]=c[i-1]+b[i];
		ans[i]=ans[i-1]+b[i]*(i-1);
	}
	long long i=1;
	while(i<=n&&n-i+1>maxn){
		for(long long j=n;j>=i;j--){
			if(ans[j]<=m&&maxn<=j-i+1)
				maxn=j-i+1;
			ans[j]-=c[j];
			c[j]-=c[i+1];
		}
		i++;
	}
	cout<<maxn;
	return 0;
} 
//5 8 -3 -1 2 2 7
