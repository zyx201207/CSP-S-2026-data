#include <bits/stdc++.h>
using namespace std;

long long c,t,n,d,x[2000005],ans,cnt,des,minn=1e18;

void dfs(int i,int st){
	if(i==des){
		if(st<minn){
			minn=st;
			cnt=1;
		}else if(st==minn) cnt++;
		return;
	}
	for(int j=i+1;j<=des;j++){
		if(x[j]-x[i]>d) break;
		dfs(j,st+1);
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				cnt=0;
				minn=1e18;
				des=j;
				dfs(i,0);
				if(cnt==2) ans++;
			}
		cout<<ans<<endl;
	}
	return 0;
}
