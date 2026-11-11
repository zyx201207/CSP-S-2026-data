#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	char c;
	int re=0,f=1;
	while (1){
		c=getchar();
		if ('0'<=c and c<='9')	break;
		if (c=='-'){
			f=-1;c='0';
			break;
		}
	}
	while (1){
		re=re*10+c-'0';
		c=getchar();
		if (!('0'<=c and c<='9'))	return re*f;
	}
}
const int N=5e5+5;
int n,m;
int a[N],qzh[N];
bool check(int x){
	for (int i=x;i<=n;i++)
		if (x*a[i]-(qzh[i]-qzh[i-x])<=m)	return 1;
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=n;i++)	a[i]=read();
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)	qzh[i]=qzh[i-1]+a[i];
	int l=0,r=n,ans;
	while (l<=r){
		int mid=(l+r)>>1;
		if (check(mid))	ans=mid,l=mid+1;
		else	r=mid-1;
	}
	cout<<ans;
} 
