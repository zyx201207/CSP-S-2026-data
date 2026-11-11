#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans,nwa,que[500005],hed,til=1;long long sum;
int read(){
	int f=1,r=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))r=(r<<3)+(r<<1)+(ch&15),ch=getchar();
	return f*r;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		que[++hed]=a[i];nwa++;
		sum+=a[i];
		while(a[i]*nwa-sum>m)sum-=a[til++],nwa--;
		ans=max(ans,nwa);
	}
	printf("%d",ans);
	return 0;
}