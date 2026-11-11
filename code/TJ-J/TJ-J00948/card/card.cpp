#include<cstdio>
#include<algorithm>
#include<stack>
int n,m;
const int maxn=5e5+5,maxm=3e5+5;
int a[maxn];
namespace Force{
	bool have[maxm];int ans[maxm];
	void solve(){
		for(int i=1;i<=n;i++){
			std::stack<int>s;
			for(int j=i;j<=n;j++){
				if(have[a[j]]){
					while(s.top()!=a[j]) have[s.top()]=false,s.pop();
				}else{
					have[a[j]]=true,s.push(a[j]);
				}
			}
			for(int j=1;j<=m;j++) ans[j]+=have[j],have[j]=false;
		}
		for(int i=1;i<=m;i++) printf("%d%c",ans[i]," \n"[i==m]);
	}
}
namespace Spe{
	int last[maxm];
	void solve(){
		for(int i=1;i<=n;i++) last[a[i]]=i;
		for(int i=1;i<=m;i++) printf("%d%c",last[i]," \n"[i==m]);
	}
}
int main(){
	//freopen("test4.in","r",stdin);
	//freopen("t.out","w",stdout);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	bool flag=true;
	for(int i=1;i<n;i++) flag=flag&&(a[i]<=a[i+1]);
	if(flag) Spe::solve();
	else Force::solve();
	return 0;
}
