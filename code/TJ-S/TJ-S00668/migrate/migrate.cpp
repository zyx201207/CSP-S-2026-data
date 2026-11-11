#include<bits/stdc++.h>
using namespace std;
long long q[2000005],st[2000005],ed,a,n,mi=1e9,sum,tp,ans;
bool vst[2000005];
void dfs(long long nw,long long cnt){
	if(nw==ed){
		st[++tp]=cnt;
		mi=min(mi,cnt);
		return;
	}
	for(long long i=1;i<=n;i++){
		if(!vst[i]&&abs(q[i]-q[nw])<=a){
			vst[i]=1;
			dfs(i,cnt+1);
			vst[i]=0;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	while(t--){
		long long b,c;
		ans=0;
		cin>>n>>a;
		for(long long i=1;i<=n;i++){
			cin>>q[i];
		}
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				ed=j;
				mi=1e9;
				tp=0;
				memset(vst,0,sizeof(vst));
				dfs(i,0);
				long long ww=0;
				for(long long k=1;k<=tp;k++){
					if(st[k]==mi)ww++;
				}
				if(ww==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
