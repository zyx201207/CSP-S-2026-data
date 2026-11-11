#include<bits/stdc++.h>
using namespace std;

const int N = 2e6+10;

int n,d,x[N]={},ans=0;

int vis[N]={},temp=0,min_step=0;
queue<pair<int,int>> q;
bool check(int a,int b){
	temp = 0;
	min_step = 1e9;
	for(int i=0;i<N;i++) vis[i]=0;
	while(q.size()) q.pop();
	q.push(make_pair(a,0)); vis[a]=1;
	
	while(q.size()){
		int id=q.front().first,step=q.front().second; q.pop();
		for(int i=id+1;i<=b&&(x[i]-x[id])<=d;i++){
			if(!vis[i]){
				q.push(make_pair(i,step+1));
				vis[i] = (i!=b);
				if(i==b&&step+1<=min_step){
					min_step = step+1;
					temp++;
				}
			}
		}
	}
	return (temp==2);
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int c,T; cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++) ans+=check(i,j);
		}
		cout<<ans<<'\n';
		ans = 0;			
	}
	return 0;
}
