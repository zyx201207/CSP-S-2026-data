#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500015;
int read(){
	int ret=0,w=1;
	char c=getchar();
	while(c<'0'||c>'9'){ 
		if(c=='-')w=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		ret=ret*10+c-'0';
		c=getchar();
	}
	return w*ret;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n,a[N],m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	int ans=0;
	int j=0,sum=0;
	for(int i=1;i<=n;i++){
		while(j<i&&(i-j)*a[i]-sum>m){
			sum-=a[j];j++;
		}
		sum+=a[i];
		ans=max(ans,i-j+1);
	}
	write(ans);
	return 0;
}
