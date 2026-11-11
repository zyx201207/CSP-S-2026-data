#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<48||ch>57){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>=48&&ch<=57){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
void print(int x){
	if(x<0){
		putchar('-');
		print(-x);
	}
	else if(x<10){
		putchar(x^48);
	}
	else{
		print(x/10);
		putchar((x%10)^48);
	}
}
int n,m,a[500010],cnt;
int q[500010],h,t;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
//	cin>>n>>m;
	for(int i=1;i<=n;i++){
		a[i]=read();
//		cin>>a[i];
	}
	sort(a+1,a+n+1);
	h=1,t=0;
	q[++t]=a[1];
	int ans=0;
	for(int i=2;i<=n;i++){
		while(h<=t&&(a[i]-q[t])*(t-h+1)+cnt>m)cnt-=q[t]-q[h],h++;
		q[++t]=a[i];
		if(h<t)cnt+=(q[t]-q[t-1])*(t-h);
		ans=max(ans,t-h+1);
	}
	print(ans);
//	cout<<ans<<'\n';
}
