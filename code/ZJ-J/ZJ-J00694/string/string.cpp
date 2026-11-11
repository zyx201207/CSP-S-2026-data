#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans,u;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	long long v=n+1;
	for(int i=1;i<=n;++i)cin>>a[i]>>c[i];
	while(u<v){
		if(a[u]>0&&a[v]==0)--v;
		else if(a[v]>0&&a[u]==0)++u;
		else if(a[u]==0&&a[v]==0)++u,--v;
		if(u>=v)break;
		if(a[u]>=a[v]){
			if(c[u]!=c[v])ans+=a[v];
			a[u]-=a[v];
			a[v]=0;
		}else{
			if(c[u]!=c[v])ans+=a[u];
			a[v]-=a[u];
			a[u]=0;
		}
	}
	cout<<ans;
	return 0;
}
//ya suo bao mi ma:Trick||Treat!
//you ji:
//zhu yi dao mei you zhong wen shu ru fa
//8:48 T1test AC
//8:53 kai T2
//9:30 T2test AC