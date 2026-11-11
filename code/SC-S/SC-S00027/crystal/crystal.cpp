#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=5e5+5;
long long n,m,ans,a[N];
long long read(){
	long long x=0,f=1;
	char a=getchar();
	while(a<'0'||'9'<a){
		if(a=='-')f=-1;
		a=getchar();
	}
	while('0'<=a&&a<='9'){
		x=x*10+a-'0';
		a=getchar();
	}
	return x*f;
}
void write(long long x){
	if(x<0)putchar('-');
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=0;i<n;i++)a[i]=read();
	sort(a,a+n);
	long long l=0,i=0;
	while(i<n-1){
		while(i<n-1&&a[i+1]==a[i])i++;
		if(i<n-1&&m>=(i+1)*(a[i+1]-a[i]))
			m-=(i+1)*(a[i+1]-a[i]);
		else break;
		i++;
	}
	ans=i+1;
	while(i<n-1){
		while(l<=i&&(i-l+1)*(a[i+1]-a[i])>m)m+=(a[i]-a[l++]);
		m-=(i-l+1)*(a[i+1]-a[i]),i++;
		while(i<n-1&&a[i+1]==a[i])i++;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}