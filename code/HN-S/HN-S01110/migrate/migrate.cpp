#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int a[N],ans=0,minn,now;
int n,d;
queue<int>q;
void dfs(int j,int res,int f){
	if(f==j){
		q.push(res);
		minn=min(res,minn);
		return;
	}
	for(int i=f+1;i<=j;i++){
		if(a[i]-a[f]<=d)dfs(j,res+1,i);
		else break;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		ans=0,now=0;
		minn=1e6;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dfs(j,0,i);
				while(!q.empty()){
					int a=q.front();
					if(a==minn)now++;
					q.pop(); 
				}
				if(now==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
}
