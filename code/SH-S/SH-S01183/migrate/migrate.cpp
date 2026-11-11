#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[5010],plan[5010],mind[5010],ans;
void dfs(int now,int step,int pass){
	if(pass>1){
		if(step<mind[now]){
			plan[now]=1;
			mind[now]=step;
		}else if(step==mind[now]){
			plan[now]++;
		}else{
			return;
		}
	}
	for(int i=1;i<=n;i++){
		if(x[now+i]-x[now]<=d&&now+i<=n)dfs(now+i,step+1,pass+1);
		else return;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(x[1]<0)x[i]-=x[1];
		}
		for(int i=1;i<=n-3;i++){
			memset(mind,0x3f,sizeof(mind));
			dfs(i,0,0);
			for(int j=1;j<=n;j++){
				if(plan[j]==2){
					ans++;
				}
			}
			memset(plan,0,sizeof(plan));
		}
		cout<<ans<<endl;
		memset(x,0,sizeof(x));
	}
	return 0;
}
