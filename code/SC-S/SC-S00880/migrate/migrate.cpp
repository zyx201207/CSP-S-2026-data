#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000005];
struct px{
	int num,cnt;
}dis[2000005];
int n,d;
void bfs(int s){
	queue<int>q;
	q.push(s);
	for(int i=1;i<=n;i++){
		dis[i]={0x3f3f3f3f3f3f3f3f,1};
	}
	dis[s].num=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
//		cout<<u<<' ';
		int l=0,r=n;
		while(l<r){
			int mid=l+r>>1;
			if(a[u]-a[mid]<=d)r=mid;
			else l=mid+1;
		}
		l=max(1ll,l);
		while(a[u]-a[l]>d)l++;
		for(int v=l;v<=n;v++){
			if(a[v]-a[u]>d)break;
			if(dis[v].num==dis[u].num+1)dis[v].cnt++;
			if(dis[v].num>dis[u].num+1){
				dis[v].num=dis[u].num+1;
				dis[v].cnt=dis[u].cnt;
				q.push(v);
			}
		}
	}
	return;
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(c==11||c==12){
			d=d/(a[2]-a[1])*(a[2]-a[1]);
			int tmp=d/(a[2]-a[1]);
//			cout<<tmp<<' ';
			if(tmp<=1)cout<<0<<'\n';
			else cout<<max(0ll,n-tmp-tmp+1)<<'\n';
			continue;
		}
		else if(c>13)cout<<0<<'\n';
		int ans=0;
		for(int i=1;i<=n;i++){
//			cout<<"!!!!";
//			cout<<i<<'\n';
			bfs(i);
			for(int j=1;j<=n;j++){
				if(dis[j].cnt==2)ans++;
//				cout<<dis[j].num<<' '<<dis[j].cnt<<'\n';
			}
		}
		ans>>=1;
		cout<<ans<<'\n';
	}
	return 0;
}
