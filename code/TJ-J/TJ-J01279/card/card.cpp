#include<cstdio>
namespace force{
	const int maxn=505,maxm=205;
	int a[maxn],x[maxn],b[maxm];
	void solve(){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++){
			int len=0;
			for(int j=i;j<=n;j++){
				bool has=false;
				for(int k=1;k<=len;k++) if(a[j]==x[k]){
					x[k]=a[j],len=k,has=true;break;
				}
				if(!has) x[++len]=a[j];
			}
			for(int i=1;i<=len;i++) b[x[i]]++,x[i]=0;
		}
		for(int i=1;i<=m;i++) printf("%d%c",b[i]," \n"[i==m]);
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	force::solve();
	return 0;
}
