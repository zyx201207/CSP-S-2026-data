#include <bits/stdc++.h>
#define int long long
#define ret return
#define mid (l+r>>1)
using namespace std;
int read(){
	int s=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
	ret s*f;
}
const int N=2e6+10;
int a[N],d,pre[N],nxt[N],b[N],cp[N],cn[N],sp[N],sn[N];
int check(int l,int r){
	vector<int> wwt,dwz;
	int now=l;
	while(now<r){
		wwt.push_back(now);
		now=nxt[now];
	}
	wwt.push_back(r);
	now=r;
	while(now>l){
		dwz.push_back(now);
		now=pre[now];
	}
	dwz.push_back(l);
	reverse(dwz.begin(),dwz.end());
	if((int)(dwz.size())!=(int)(wwt.size()))ret 0;
	int sum=0;
	for(int i=0;i<dwz.size();i++)sum+=abs(dwz[i]-wwt[i]);
	ret sum==1;
}
int solve(int l,int r){
	if(r-l<=2)ret 0;
	for(int i=l+1;i<=r;i++)if(a[i]-a[i-1]>d)ret solve(l,i-1)+solve(i,r);
	for(int i=l;i<=r;i++)b[i-l+1]=a[i];int n=r-l+1;
	for(int i=1;i<=n;i++)sp[i]=sn[i]=0;
	pre[1]=0,nxt[n]=0;cp[1]=cn[n]=1;
	for(int lst=1,i=2;i<=n;i++){
		while(b[i]-b[lst]>d)lst++;
		pre[i]=lst;sp[lst]++;
	}
	for(int lst=n,i=n-1;i;i--){
		while(b[lst]-b[i]>d)lst--;
		nxt[i]=lst;sn[lst]++;
	}
	if(n<=300){
		int tot=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				tot+=check(i,j);
			}
		}ret tot;
	}
	for(int i=2;i<=n;i++){if(nxt[pre[i]]==i)cp[i]=cp[pre[i]]+1;else cp[i]=1;}
	for(int i=n-1;i;i--){if(pre[nxt[i]]==i)cn[i]=cn[nxt[i]]+1;else cn[i]=1;}
	int ans=0;
	for(int i=3;i<n;i++){
		if(nxt[pre[i]]!=i)continue;if(pre[nxt[i-1]]!=i-1)continue;
		if(pre[i]!=pre[i-1]&&nxt[i]!=nxt[i-1])ans+=(pre[i]!=i-1&&nxt[i-1]!=i);
		if(pre[i]==pre[i-1]&&nxt[i]!=nxt[i-1])ans+=cp[pre[i]]*sp[i-1];
		if(pre[i]!=pre[i-1]&&nxt[i]==nxt[i-1])ans+=cn[nxt[i]]*sn[i];
		if(pre[i]==pre[i-1]&&nxt[i]==nxt[i-1])
		ans+=cp[pre[i]]*cn[nxt[i]]+cp[pre[i]]*(sp[i-1]-1)+(sn[i]-1)*cn[nxt[i]];
	}
	ret ans;
}
void wwt(){
	int n=read();d=read();
	for(int i=1;i<=n;i++)a[i]=read();
	printf("%lld\n",solve(1,n));
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int op=read(),t=read();while(t--)wwt();
	ret 0;
}
