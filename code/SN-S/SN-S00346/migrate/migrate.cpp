//张芃浩 西安交通大学附属中学 SN-S00346 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mx=1e18;
int n,d,x[2000001],dis[2000001],to[2000001];
int cnt[2000001];
int rch[1000001][21];//i经过j步能走到哪里 
void work(int c){
	int ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int i=1,j=1;i<=n;i++){
		while(j<n&&x[j+1]-x[i]<=d)j++;
		to[i]=j;
	}
	if(c==11||c==12){
		int stp=to[1]-1;
		if(stp<2)cout<<0<<'\n';
		else cout<<max(0LL,n+1-2*stp)<<'\n';
		return;
	}
	if(c>=13&&c<=14){
		for(int i=1;i<=n;i++){
			int a=to[to[i]],b=to[to[i]-1],c=to[to[i]-2];
			if(a==to[i])continue;
			ans+=b-max(to[i],c);
		}
		cout<<ans<<'\n';
		return;
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++)dis[j]=mx;
		dis[i]=0;
		for(int j=i-1;j;j--){
			if(to[j]>i)dis[j]=1;
			else dis[j]=dis[to[j]]+1;
		}
		cnt[i]=1;
		for(int j=i-1;j;j--){
			int v=min(to[j],i);
			if(dis[j]>=mx)cnt[j]=0;
			else if(dis[v]!=dis[v-1])cnt[j]=cnt[v];
			else if(dis[v]==dis[v-1]&&dis[v]!=dis[v-2]&&cnt[v]==1&&cnt[v-1]==1)cnt[j]=2;
			else cnt[j]=3;
			if(cnt[j]==2)ans++;
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)work(c);
	return 0;
}
