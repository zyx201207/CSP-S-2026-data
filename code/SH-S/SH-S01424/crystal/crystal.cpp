#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+7;
ll in(){
	bool flag=0;
	ll num=0;
	char c;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')
			flag=1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		num=num*10+c-'0';
		c=getchar();
	}
	if(flag)
		num=-num;
	return num;
}
void out(int num){
	if(num<0){
		putchar('-');
		num=-num;
	}
	if(num>9)
		out(num/10);
	putchar('0'+num%10);	
}
int n,ans,p;
ll a[N],sum[N],m,res;
ll f(int x,int idx){
	return 1ll*(x-idx)*a[x]-(sum[x-1]-sum[idx-1]);
}
int solve(int x){
	int l=1,r=x,mid;
	while(r-l>1){
		mid=(r+l)>>1;
		if(f(x,mid)<=res)
			r=mid;
		else
			l=mid+1;
	}
	if(f(x,l)<=res)
		return l;
	else
		return r;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=in(),m=in();
	for(int i=1;i<=n;i++)
		a[i]=in();
	res=m;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		sum[i]=a[i]+sum[i-1];
	for(int i=2;i<=n;i++){
		p=solve(i);
		ans=max(ans,i-p+1);
	}
	out(ans);
	fclose(stdin);
	fclose(stdout);
}
