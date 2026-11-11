#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int n,m,a[maxn][35],sum[35],hvb[maxn];long long ans;bool f[maxn];
int read(){
	int f=1,r=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))r=(r<<3)+(r<<1)+(ch&15),ch=getchar();
	return f*r;
}
void st(int pos,int num){
	for(int i=1;num>0;i++){
		a[pos][i]=num%2;
		num/=2;
	}
}
long long gtans(int pos){
	pos--;
	for(;pos>0;pos--)if(sum[pos]>=m)break;
	if(pos<=0)return 0;
	int cnt=0;
	for(int i=1;i<=n;i++)hvb[i]=0;
	for(int i=1;i<=pos;i++)sum[i]=0;
	for(int i=1;i<=n;i++){
		if(a[i][pos])hvb[++cnt]=i;
	}
	for(int i=1;i<=cnt;i++)
	for(int j=1;j<=pos;j++)
		sum[j]+=a[hvb[i]][j];
	return (1<<pos-1)+gtans(pos);
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		st(i,read());
	}
	for(int i=1;i<=30;i++){
		for(int j=1;j<=n;j++)sum[i]+=a[j][i];
	}
	ans=gtans(30);
	printf("%lld",ans);
	return 0;
}