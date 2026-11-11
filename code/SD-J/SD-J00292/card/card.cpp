#include<cstdio>
#include<algorithm>
using namespace std;
const int N=5e5+5;
int a[N],cnt[N],p[N],nx[N],ans[N];
struct O{int v,p;}o[N];
bool cmp(O a, O b){return a.p>b.p;}
int main(){
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",a+i);
		cnt[a[i]]++;
		p[a[i]]=i;
		
	}
	for(int i=1;i<=m;++i){
		o[i].v=i;
		o[i].p=p[i];
		if(p[i]<n)nx[i]=a[p[i]+1];
		else nx[i]=0;
		
	}
	sort(o+1,o+m+1,cmp);
	for(int i=1;i<=m;++i){
		int v=o[i].v;
		ans[v]+=cnt[v];
		if(nx[v])ans[nx[v]]+=ans[v]; 
	}
	for(int i=1;i<=m;++i)
	printf("%d",ans[i]);
	return 0;
} 
