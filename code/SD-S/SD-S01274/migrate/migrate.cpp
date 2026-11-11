#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,T,n,d;
int x[N];
int minn,cnt;
void dfs(int now,int e,int num){
	if(now==e){
		if(num==minn) cnt++;
		if(num<minn){
			minn=num;
			cnt=1;
		}
		return ;
	}
	if(num>minn){
		return ;
	}
	for(int i=now+1;i<=n;i++){
		if(x[i]-x[now]<=d){
			dfs(i,e,num+1);
		}
		else{
			break;
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cnt=0;
				minn=0x3f3f3f3f;
				dfs(i,j,0);
				if(cnt==2) ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
