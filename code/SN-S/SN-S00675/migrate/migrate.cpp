#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,cnt=0;
long long xk[2000000+10];
struct node{
	int v,dis;
};
queue<int>qe;
int dis[2000000+10];
int ans[2000000+10];
bool f[2000000+10];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			int ank=1;
			cin>>n>>d;
			int kl=0;
			for(int i=4;i<=n;i++){
				ank+=kl;
				kl++;
			}
			cout<<ank<<endl;
		}
		return 0;
	}
	if(c==13||c==14){
		while(t--){
			int ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>xk[i];
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(abs(xk[i]-xk[j])>d){
						ans+=n-j+1;
					}
				}
			}
			cout<<ans;
		}
		return 0;
	}
	while(t--){		
		cnt=0;
		cin>>n>>d;
		vector<node>edge[n+10];
		for(int i=1;i<=n;i++){
			cin>>xk[i];
		}
		for(int i=1;i<=n;i++){
			int nowx=xk[i];
			for(int j=i+1;j<=n;j++){
				if(i==j)continue;
				if(abs(nowx-xk[j])<=d){
					edge[i].push_back({j,1});
//					edge[j].push_back({i,1});
				}else{
					if(j>i){
						break;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){				
				int st=i;
				for(int i=1;i<=n+100;i++){
					dis[i]=0x3f;
					ans[i]=0;
					f[i]=0;
				}
				qe.push(st);
				f[st]=1;
				dis[st]=0;
				while(!qe.empty()){
					int vv=qe.front();
					qe.pop();
					f[vv]=1;
					for(node vk:edge[vv]){
						if(f[vk.v]==true){
							continue;
						}
//						f[vk.v]=true;
						if(dis[vk.v]==dis[vv]+vk.dis){
							ans[vk.v]++;
						}
						if(dis[vk.v]>dis[vv]+vk.dis){
							ans[vk.v]=0;
							dis[vk.v]=dis[vv]+vk.dis;				
						}
						qe.push(vk.v);
					}
				}				
				if(ans[j]>1){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
/*
4
1 2 2
2 4 3
3 4 5
1 3 1

4
1 2 3
2 3 4
3 4 5
4 5 6

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/

