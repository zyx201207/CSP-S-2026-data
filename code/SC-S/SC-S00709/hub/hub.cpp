#include<bits/stdc++.h>
#define N 1000005
#define int long long
#define endl '\n'
#define PII pair<int,int>
using namespace std;

int c,t,n,k;
vector<int> e[N];

int getans(int x){
	return x*(x+1)/2;
}

signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
//	freopen("hub.in","r",stdin);
//	freopen("hub_my.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%lld%lld",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		int m=n/2,tmp=m-k/2,tmp2=m+1-k+k/2;
		int ans1=getans(tmp/2),ans2=getans(tmp-tmp/2),ans3=getans(tmp2-tmp2/2),ans4=getans(tmp2);
		printf("%lld\n",ans1+ans2+ans3+ans4);
	}
	return 0;
}//知颖你太美