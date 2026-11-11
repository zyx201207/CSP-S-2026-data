#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T;
int n,m,ans=0;
int minn=999999999,mm=0;
int a[2000005];
vector<int>e[2000005];
bool vis[2000005];
void dfs(int step,int head,int teil){
	if(step==teil){
		minn=min(minn,mm);
		return ;
	}
	for(int i = 0;i < e[step].size();i++){
		mm++;
		dfs(e[step][i],head,teil);
		mm--;
	}
	return ;
}
bool flag;
void dfs2(int step,int head,int teil,int size){
	if(vis[step]&&step!=teil){
		return ;
	}
	if(step==teil){
		if(size!=minn){
			return ;
		}
		ans++;
		flag=1;
		return ;
	}
	for(int i = 0;i < e[step].size();i++){
		dfs2(e[step][i],head,teil,size+1);
		if(step==head){
			flag=0;
		}
		if(flag==1){
			vis[step]=1;
			return ;
		}
	}
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		for(int i = 1;i <= n;i++){
			cin>>a[i];
		}
		int sum=0;
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				for(int q = 1;q <= n;q++){
					e[q].clear();
				}
				for(int q = 1;q <= n;q++){
					for(int p = q + 1;p <= n;p++){
						if(a[p]<=a[q]+m){
							e[q].push_back(p);
						}else{
							break;
						}
					}
				}
				minn=999999999,mm=0,ans=0;
				for(int i = 1;i <= n;i++){
					vis[i]=0;
				}
				dfs(i,i,j);
				dfs2(i,i,j,0);
				if(ans==2){
					sum++;
				}
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
