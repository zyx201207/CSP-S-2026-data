#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long n,m,t,a[N],dis[N][2],c;
bool cmp(long long a,long long b){
	return a<b;
}
struct node{
	int x,d;
};
queue<node>q;
void bfs(int x){
	for(int i=x;i<=n;i++){
		dis[i][0]=2e18;
		dis[i][1]=0;
	}
	q.push({x,0});
	while(q.size()){
		node t=q.front();
		q.pop();
		if(dis[t.x][0]>t.d){
			dis[t.x][0]=t.d;
			dis[t.x][1]=1;
		}
		else if(dis[t.x][0]==t.d){
			dis[t.x][1]++;
		}
		else{
			continue;
		}
		for(int i=t.x;i<=n;i++){
			if((a[i]-a[t.x])>m){
				break;
			}
			if(dis[i][0]<=t.d)continue;
			q.push({i,t.d+1});
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		long long ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<n-2;i++){
			bfs(i);
			for(int j=i;j<=n;j++){
				ans+=(dis[j][1]==2);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}