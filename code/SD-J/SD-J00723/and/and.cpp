#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;
int n,m,ans_cnt;
int arr[N],ans[N],sum[35];

inline int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}

inline int print(int x) {
	if(x<0) x=-x,putchar('-');
	if(x>9) print(x/10);
	putchar(x%10+'0');
}

inline void init(int x) {
	int tmp[35],cnt=0;
	memset(tmp,0,sizeof tmp);
	while(x) {
		tmp[++cnt]=x&1;
		x>>=1;
	}
	for(int i=1;i<=cnt;i++) if(tmp[i]) sum[i]++;
}

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) arr[i]=read(),init(arr[i]);
	bool fl;
	for(int i=32;i>=1;i--) {
		if(sum[i]>=m) {
			for(int j=1;j<=n;j++) if((arr[j]>>(i-1))&1) ans[++ans_cnt]=arr[j];
			sort(ans,ans+ans_cnt+1);
			int res=ans[ans_cnt];
			for(int j=ans_cnt-1;j>=ans_cnt-m+1;j--) res&=ans[j];
			print(res);
			fl=1;
			break;
		}
	}
	if(!fl) print(0);
	return 0;
}
