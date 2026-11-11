#include<cstdio>
#include<algorithm>

namespace zxz{
	const int N=500005,M=300005;
	int n,m,a[N],lst[M],cnt[M],id[M];
	bool cmp(int i,int j){
		return lst[i]>lst[j];
	}
	void solve(){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),lst[a[i]]=i,cnt[a[i]]++;
		for(int i=1;i<=m;i++) id[i]=i;
		std::sort(id+1,id+1+n,cmp);
		for(int i=m;i>1;i--){
			cnt[a[lst[id[i]]+1]]+=cnt[id[i]];
		}
		for(int i=1;i<=m;i++) printf("%d%c",cnt[i]," \n"[i==m]);
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	zxz::solve();
	return 0;
}
