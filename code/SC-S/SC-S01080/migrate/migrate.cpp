#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e3+4;
int a[MAXN];
vector<int>g[MAXN];
int n,d;
bool flag[MAXN];
bool bfs(int s,int e){
	memset(flag,0,sizeof(flag));
	queue<int>q;
	queue<int>q1;
	q.push(s);
	q1.push(0);
	int mia=1e9,ans=0;
	flag[s]=1;
	while(!q.empty()){
		int x=q.front(),road=q1.front();
		q.pop(),q1.pop();
		if(x==e){
			if(mia>road){
				ans=1;
				mia=road;
			}else if(mia==road){
				ans++;
			}
			continue;
		}
		for(int i=0;i<int(g[x].size());i++){
			int k=g[x][i];
			if(flag[k]==0){
				flag[k]=1;
				q.push(k);
				q1.push(road+1);
			}
		}
	}
	return (ans==2);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int tmpc,T;
	cin>>tmpc>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			int j=n-1;
			while(a[i]-a[j]<=d){
				g[j].push_back(i);
				j--;
			}
		}
		int res=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(bfs(i,j))res++;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}