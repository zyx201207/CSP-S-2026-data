#include<bits/stdc++.h>
using namespace std;
#define int long long
int f[1005][1005],g[1005][1005],n,d,a[2000005],c,T,spl[2000005],cnt,minn;
void dfs(int x,int y,int st){
	if(x==y){
		if(st==minn)cnt++;
		else if(minn>st)minn=st,cnt=1;
		return;
	}
	for(int i=x+1;i<=y;i++){
		if(a[i]-a[x]>d)break;
		dfs(i,y,st+1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		int ans=0,pre=0,flag=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>2){
				if(a[i]-a[i-1]!=pre)flag=1;
			}
			if(i==1)pre=a[i]-a[i-1];
		}
		if(!flag&&n>9){
			if(pre>=d*2&&pre<d*3)cout<<n-3<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cnt=0;minn=1e9;
				dfs(i,j,0);
				if(cnt==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
