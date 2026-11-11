#include<bits/stdc++.h>
using namespace std;
int c,T,n,m,j;
int ans;
int a[2000005];
int bfs(int x,int y){
	queue<pair<int,int> > q;
	q.push({x,0});
	while(q.size()!=0){
		pair<int,int> o=q.front();
		int r=o.first;
		q.pop();
		if(r==y) return o.second;
		int h=r+1;
		while((a[h]-a[r])<=m&&h<=y){
			q.push({h,h-r});
			h++;
		}
	}
}
void dfs(int x,int sum,int sj,int y){
	if(sum>sj) return;
	if(x==y){
		j++;
		return ;
	}
	int h=x+1;
	while((a[h]-a[x])<=m&&h<=y){
		dfs(h,sum+1,sj,y);
		h++;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		ans=0;
		int s=1;
		vector<int> q;
		cin>>n>>m;
		for(int t=1;t<=n;t++){
			cin>>a[t];
			if(t>1&&a[t]-a[t-1]>m) q.push_back(t);
		}
		q.push_back(n);
		for(int t=0;t<q.size();t++){
			for(int l=s;l<q[t]-1;l++){
				for(int r=l+3;r<=q[t];r++){
					int zu=bfs(l,r);
					j=0;
					dfs(l,0,zu,r);
					if(j==2){
						ans++; 
					}
				}
			}
			s=q[t]+1;
			if(s>n) break;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
