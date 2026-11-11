#include<bits/stdc++.h>
#define int long long
using namespace std;
int x[2000002];
unordered_map<int,int>mp;//real - idx
vector<int>a[2000002];
int dis[5002][5002];
int cnt[5002][5002];
signed main(){
	//神秘DP想不出来 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				dis[i][j]=2e7;
				cnt[i][j]=0;
			}
			
		}
		for(int i=1;i<=n;i++)a[i].clear();
		for(int i=1;i<=n;i++){
			cin>>x[i];
			for(int j=1;j<i;j++){
				if(x[i]-x[j]<=d){
					a[j].push_back(i);
				}
			}
			mp[x[i]]=i;
		}
		
		for(int i=1;i<=n;i++){
			queue<int>q;
			q.push(i);
			cnt[i][i]=1;
			dis[i][i]=0;
			while(!q.empty()){
				int p=q.front();
				q.pop();
				for(auto j:a[p]){
					if(dis[i][j]>dis[i][p]+1){
						
						dis[i][j]=dis[i][p]+1;
						cnt[i][j]=cnt[i][p];
						q.push(j);
	//					cout<<p<<"->"<<j<<"New:"<<cnt[i][j]<<" \n";
					}else if(dis[i][j]==dis[i][p]+1){
						cnt[i][j]++;
	//					cout<<p<<"->"<<j<<"Upd:"<<cnt[i][j]<<" \n";
					//	q.push(j);
					}
					
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
	//			cout<<cnt[i][j]<<" ";
				if(cnt[i][j]==2){
					ans++;
				}
			}
	//		cout<<"\n";
		}
		cout<<ans<<"\n";
	} 
	return 0;
}


/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/

	//反飞之鸟 哦 不是 1653 dp 1658
