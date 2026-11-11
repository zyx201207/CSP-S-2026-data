#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=500010,M=300010;
int a[N],p[N],la[M],lif[N],mx;
long long ans[M],t[M];
int read(){
	int k=0;
	char ch=getchar();
	while(ch>'9'||ch<'0')ch=getchar();
	while(ch>='0'&&ch<='9'){
		k=(k<<1)+(k<<3)+(ch^48);
		ch=getchar();
	}
	return k;
}
void liv(int x){
	for(int i=n;i>=x;i--)
		if(p[i]>=x){
			lif[x]=lif[i];
			return;
		}
	lif[x]=n-x+1;
	mx=max(mx,lif[x]);
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)a[i]=read();
	memset(la,-1,sizeof(la));
	memset(p,-1,sizeof(p));
	for(int i=1;i<=n;i++){
		if(la[a[i]]!=-1)p[i]=la[a[i]];
		la[a[i]]=i;
	}
	for(int i=n;i>=1;i--)liv(i);
	sort(lif+1,lif+n+1);
	for(int i=1;i<=n;i++){
		for(int j=n-lif[i]+1;j<=n;j++)ans[a[j]]++;
	}
	for(int i=1;i<=m;i++)printf("%lld ",ans[i]);
	return 0;
}
