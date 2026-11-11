#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=2000010;
int c,t,n,y,minn,cnt;
ll d,x[N];
void dfs(int u,int s){
	if(u==y){
		if(s<minn)cnt=1,minn=s;
		else cnt++;
		return;
	}
	if(s>=minn)return;
	for(int i=n;i>u;--i)
		if(x[i]-x[u]<=d)dfs(i,s+1);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;++i)scanf("%lld",x+i);
		ll ans=0;
		if(n<=9){
			for(int i=1;i<=n;++i)
				for(int j=i+3;j<=n;++j){
					cnt=0;
					minn=N;
					y=j;
					dfs(i,0);
					if(cnt==2)
						++ans;
				}
			printf("%lld\n",ans);
		}
//		else if(c==13||c==14){
//			int r1=1,ln=n;
//			for(int i=2;i<=n;++i)
//				if(x[i]-x[1]<=d)r1=i;
//				else break;
//			for(int i=n-1;i;--i)
//				if(x[n]-x[i]<=d)ln=i;
//				else break;
//			printf("%lld")
//		}
	}
	return 0;
}
