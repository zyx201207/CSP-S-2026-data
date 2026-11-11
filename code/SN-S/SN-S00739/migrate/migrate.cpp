#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,d,a[2000005],tot=0,ans=0,v,minn;
bool f[2000005];
void dfs(int x,int step){
	if(x!=v&&step>=minn) return ;//若没到达终点就和之前的最小值一样大。甚至更大，则一定不成立 
	if(x==v){//到达v点 
		if(step<minn){
			minn=step;//更新最小值和最小路线数量 
			tot=1;
		}
		else if(step==minn) tot++;
		return ;
	}
	for(int i=x+1;i<=v;i++){
		if(a[i]-a[x]>d) break;//如果飞不到就跳出 
		dfs(i,step+1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				tot=0;
				minn=1e18;
				v=j;
				dfs(i,0);//i->j
				if(tot==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//我部畅通无阻。 
