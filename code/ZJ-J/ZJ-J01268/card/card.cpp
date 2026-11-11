#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ccf[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		bool vis[300005]={};
		stack<long long>foosball;
		for(int j=i;j<=n;j++) if(vis[a[j]]==1){
			while(foosball.top()!=a[j]) vis[foosball.top()]=0,foosball.pop();
	 	}else vis[a[j]]=1,foosball.push(a[j]);
		while(!foosball.empty()) ccf[foosball.top()]++,foosball.pop();
	}
	for(int i=1;i<=m;i++) printf("%lld ",ccf[i]);
	return 0;
}
//luogu uid:1053642
//shen mi de bian liang ming
//foosball shi wo men jiao lian
//f**k ccf
//ping ce ji jiu ming
//mei wei de TLE ci bu ci
//wo xiang shang ZJ mi huo xing wei da shang
//100->56 TLE44 f**king
//T1 qian dao
//T2 qian dao
//T3 tan xin
//T4 wo ye bu zhi dao
//ping ce ji~~~ rang wo na 80 ze me yang???
//52.76s hyw
