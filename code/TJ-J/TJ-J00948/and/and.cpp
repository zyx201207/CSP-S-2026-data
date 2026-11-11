#include<cstdio>
#include<algorithm>
#include<cassert>
#include<vector>
int n,m;
const int maxn=2e5+5,maxm=2e5+5,maxk=30+2;
int a[maxn];bool p[maxk][maxn];
int main(){
	//freopen("test3.in","r",stdin);
	//freopen("t.out","w",stdout);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) for(int k=maxk-1;k>=0;k--) p[k][i]=a[i]>>k&1;
	//for(int i=1;i<=n;i++){for(int k=maxk-1;k>=0;k--) printf("%d",p[k][i]); puts("");}
	std::vector<int>v;
	for(int i=1;i<=n;i++) v.push_back(i);
	for(int k=maxk-1;k>=0;k--){
		std::vector<int>nv;
		for(int i:v) if(p[k][i]) nv.push_back(i);
		if((int)nv.size()>=m) v=nv;
		if((int)nv.size()==m) break;
	}
	//assert((int)v.size()>=m);
	int ans=a[v[0]];
	for(int i=1;i<m;i++) ans&=a[v[i]];
	printf("%d\n",ans);
	return 0;
}
