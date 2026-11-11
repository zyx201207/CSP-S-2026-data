/*
 * 镜中人 定格在少年
 * 同心者 万里也并肩
 * 在火树银花照亮那瞬间
 * 忽忆起昔年 共一卷
 * 兜兜转转再趟一遍人间
 * 再同你看那弯旧月
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 2000004
int tid;
int n;ll d,x[N],ans;
int l[N],r[N],L[N],R[N];
int f[N],fl,g[N],gl;
int c[N];
void MoLing_qwq(){
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;++i)scanf("%lld",&x[i]);
	for(int i=n,j=n;i>=1;--i){
		while(j>1&&x[i]-x[j-1]<=d)--j;
		l[i]=j;
	}
	for(int i=1,j=1;i<=n;++i){
		while(j<n&&x[j+1]-x[i]<=d)++j;
		r[i]=j;
	}
	l[n+1]=n;
	for(int i=1;i<=n;++i){
		if(l[i]==i||r[l[i]]!=i)L[i]=0;
		else L[i]=L[l[i]]+l[i+1]-l[i];
	}
	r[0]=1;
	for(int i=n;i>=1;--i){
		if(r[i]==i||l[r[i]]!=i)R[i]=0;
		else R[i]=R[r[i]]+r[i]-r[i-1];
	}
	//for(int i=1;i<=n;++i)cerr<<L[i]<<" "<<R[i]<<endl;
	ans=0;
	for(int x=1;x<=n;++x){
		int y=r[r[x]];
		if(l[y]==r[x]-1&&l[l[y]]==x)ans+=((ll)(L[x]))*((ll)(R[y]));
	}
	for(int x=1;x<=n;++x){
		int y=r[r[x]];
		if(l[y]==r[x]-1)ans+=((ll)(R[y]));
	}
	for(int y=1;y<=n;++y){
		int x=l[l[y]];
		if(l[y]==r[x]-1)ans+=((ll)(L[x]));
	}
	for(int i=0;i<=n+1;++i)c[i]=0;
	for(int x=n;x>=1;--x)ans+=c[r[x]-1],++c[l[x]];
	for(int x=1;x<n;++x)if(r[x]==x+1&&l[x+1]==x)--ans;
	/*for(int x=1;x<=n;++x)for(int y=x+1;y<=n;++y)
		if(l[y]==r[x]-1&&l[y]!=x)++ans;*/
	
	/*for(int x=1;x<=n;++x)for(int y=x+1;y<=n;++y){
		bool ok=0;
		f[fl=1]=x;
		while(f[fl]!=y){
			if(r[f[fl]]==f[fl]){ok=1;break;}
			f[fl+1]=min(r[f[fl]],y),++fl;
		}
		g[gl=1]=y;
		while(g[gl]!=x){
			if(l[g[gl]]==g[gl]){ok=1;break;}
			g[gl+1]=max(l[g[gl]],x),++gl;
		}
		if(ok)continue;
		if(fl!=gl)continue;
		int cnt=0;
		for(int i=1;i<=fl;++i){
			if(abs(f[i]-g[fl+1-i])>1){cnt=-1;break;}
			if(f[i]!=g[fl+1-i]){
				++cnt;
			}
		}
		if(cnt==1)++ans;
	}*/
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
	scanf("%d%d",&tid,&T);
	while(T--)MoLing_qwq();
	return 0;
}
