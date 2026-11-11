#include<bits/stdc++.h>
using namespace std;
const int N=2e6+9;
int c,T;
int n;long long d,ans; 
long long pos[N],nex[N],minn[N];
bool vis[N],vis2[N];
void solve(int last){
	for(int i=1;i<=last;i++){
		if((pos[last]-pos[i])<=d) nex[i]=last;
		else nex[i]=upper_bound(pos+1,pos+1+last,pos[i]+d)-pos-1;
		vis[i]=vis2[i]=false;
	}
	minn[last]=0;vis[last]=true;
	for(int i=last-1;i>=1;i--){
		if(nex[i]==i) break;
		minn[i]=minn[nex[i]]+1;
		if(nex[i]==i+1||(minn[nex[i]]!=minn[nex[i]-1]&&vis[nex[i]])) vis[i]=true;
		bool flag=true;int tot1=0,tot2=0,tot3=0;
		for(int j=nex[i];j>i;j--){
			if(minn[j]==minn[nex[i]]){
				if(vis[j]&&vis2[j]) tot3++;
				else if(vis[j]) tot1++;
				else if(vis2[j]) tot2++;
				else{ flag=false;break; }
			}else{ break; }
		}
		if(!flag) continue;
		if((tot1==2&&tot2==0&&tot3==0)||(tot1==0&&tot2==1&&tot3==0)||(tot1==0&&tot2==0&&tot3==1)){
			ans++;vis2[i]=true;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d%lld",&n,&d);ans=0;
		for(int i=1;i<=n;i++) scanf("%lld",&pos[i]);
		for(int i=n;i>=1;i--) solve(i);
		printf("%lld\n",ans);
	}
	return 0;
}