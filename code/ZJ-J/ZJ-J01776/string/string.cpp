#include<bits/stdc++.h>
using namespace std;
const int MA=200005;
#define int long long
int n;
int a[MA];
char p[MA];
int le,ri,pl,pr;
long long ans;
int read()
{
	int f=1,x=0;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return f*x;
}
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		cin>>p[i];
	}
	le=1;
	ri=n;
	pl=1;
	pr=a[n];
	while(1){
		if(p[le]!=p[ri]){
			int minn=min(a[le]-pl,pr-1)+1;
			pl+=minn;
			pr-=minn;
			ans+=minn;
		}
		else{
			int minn=min(a[le]-pl,pr-1)+1;
			pl+=minn;
			pr-=minn;		
		}
		if(pl>a[le]){
			le++;
			pl=1;
		}
		if(pr==0){
			ri--;
			pr=a[ri];
		}
		if((le>ri)||(le==ri&&pl==pr)||(le==ri&&pl>pr)) break;
	}
	printf("%lld",ans);
}
