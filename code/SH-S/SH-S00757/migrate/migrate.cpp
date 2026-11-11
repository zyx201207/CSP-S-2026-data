#include<bits/stdc++.h>

using namespace std;
int arr[2000005]={};
int cnt=0,n,d;
struct node{
	int x,step;
};
int minstep=0;
bool bfs(int s,int e){
	queue<node>q;
	q.push({s,0});
	bool flag=1;
	while(!q.empty()){
		node nod=q.front();
		q.pop();
		int x=nod.x;
		int step=nod.step;
		for(int i=1;i<=n;i++){
			if(abs(arr[i]-arr[x])>d||i==x){
				continue;
			}
			if(i==e){
				minstep=step+1;
				cnt++;
				flag=0;
			}
			q.push({i,step+1});
		}
		if(step+1>minstep&&flag==0){
			return 1;
		}
		if(step>n){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		minstep=0;
		int ans=0;
		bool ffff=1;
		memset(arr,0,sizeof arr);
		for(int i=1;i<=n;i++){
			cin>>arr[i];
			if(arr[i]%d!=0){
				ffff=0;
			}
		}
		if(ffff){
			for(int i=1;i<=n;i++){
				arr[i]=arr[i]/d;
			}
			d=1;
		}
		for(int i=1;i<=n-2;i++){
			for(int j=i+2;j<=n;j++){
				if(bfs(i,j)){
					if(cnt==2){
						ans++;
					}
				}
				cnt=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//燃尽了暴力写了76行只能过两个点 
