#include<bits/stdc++.h>
using namespace std;
int c,t,n,sum;
long long d,a[2000005],dis[5005][5005],num[5005][5005];
struct node{
	int u;
	long long d;
};
bool operator<(const node&a,const node&b){
	return a.d>b.d;
}
priority_queue<node>q;
int f(int y){
	int ans=0;
	dis[y][y]=0;
	q.push({y,0});
	while(!q.empty()){
		while(!q.empty()&&q.top().d>dis[y][q.top().u])q.pop();
		if(q.empty())break;
		node x=q.top();
		q.pop();
		for(int i=x.u+1;a[i]-a[x.u]<=d&&i<=n;i++){
			if(dis[y][x.u]+1<dis[y][i]){
				if(num[y][i]==2)ans--;
				num[y][i]=1;
				dis[y][i]=dis[y][x.u]+1;
				q.push({i,dis[y][i]});
			}
			else if(dis[y][x.u]+1==dis[y][i]){
				num[y][i]++;
				if(num[y][i]==2)ans++;
				if(num[y][i]==3)ans--;
				q.push({i,dis[y][i]});
			}
		}
	}
	return ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		sum=0;
		memset(dis,0x3f,sizeof(dis));
		memset(num,0,sizeof(num));
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i!=1)dis[i-1][i]=1;
		}
		for(int i=1;i<=n-3;i++)sum+=f(i);
		cout<<sum<<endl;
	}
	return 0;
}