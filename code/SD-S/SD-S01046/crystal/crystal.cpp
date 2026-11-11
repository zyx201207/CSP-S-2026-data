#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define re register
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar('0'+x%10);
}
long long a[200005],n,m,cf[200005]={0},pre[5005][5005]={0};
int ef(int s,int end,int x){
	int l=s,r=end;
	while(l<r){
		int mid=l+(r-l)/2;
		if(pre[end][mid]<=x)r=mid;
		else l=mid+1;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	ll c=a[2]-a[1];
	bool f=0;
	for(int i=1;i<=n;i++)if((a[i]-a[i-1])!=c)f=1;
	if(f==0){
		int aa=0;
		for(int i=1;i<=n;i++){
			m-=(c*i);
			if(m>=0)aa++;
			else break;
		}
		write(aa+1);
		return 0;
	}
	for(int i=1;i<=n;i++){
		cf[i]=a[i]-a[i-1];
	}
	for(int i=2;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			pre[i][j]=pre[i][j+1]+a[i]-a[j];
		}
		pre[i][i]=0;
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		int k=ef(1,i,m);
		ans=max(ans,i-k+1);
	}
	/*for(int i=1;i<=n;i++){
		write(cf[i]);
		putchar(' ');
	}
	putchar('\n');
	for(int i=1;i<=n;i++){
		write(pre[i]);
		putchar(' ');
	}
	putchar('\n');*/
	write(ans);
	return 0;
}

