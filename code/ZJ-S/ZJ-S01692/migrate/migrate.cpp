#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long ans=0,f=1;
	char s=getchar();
	while(s!='-'&&(s>'9'||s<'0')) s=getchar();
	if(s=='-') s=getchar(),f=-1;
	while(s>='0'&&s<='9') ans=ans*10+s-'0',s=getchar();
	return ans*f;
}
long long a[2000005];
int nxt[2000005],pre[2000005],step[2000005],top[200005],stepq[2000005],flag[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
	scanf("%d%d",&T,&T);
	while(T--){
		int n;
		long long d;
		scanf("%d",&n);
		d=read();
		for(int i=1;i<=n;i++) a[i]=read();
		int l=1;
		for(int i=1;i<=n;i++){
			while(l<i&&a[l]+d<a[i]) nxt[l]=i-1,l++;
			pre[i]=l;
			step[i]=0;
			stepq[i]=0;
		}
		for(int i=l;i<=n;i++) nxt[i]=n;
		for(int i=n;i>=1;i--)
			if(nxt[i]!=i) step[i]=step[nxt[i]]+1;
		for(int i=1;i<=n;i++)
			if(nxt[i]!=i) stepq[nxt[i]]=stepq[i]+1;
		for(int i=n;i>=1;i--){
			int now=pre[i];
			while(now!=pre[now]) now=pre[now];
			for(int j=now;j<=i;j++) top[j]=i;
			i=now;
		}
		long long ans=0;
		for(int i=1;nxt[i]<n;i++){
			if(nxt[i]==top[i]){
				i=nxt[i];
				continue;
			}
			if(nxt[i]>=i+2&&nxt[nxt[i]-1]!=nxt[nxt[i]-2]) ans+=(nxt[nxt[i]-1]-nxt[nxt[i]-2])*(step[nxt[nxt[i]]]+1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/