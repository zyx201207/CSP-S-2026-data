#include<bits/stdc++.h>
#include<string>
#include<vector>
#define ll long long
using namespace std;
ll c,T,n,d,cnt,a[500005],v[5005][5005];
struct node{
	ll zd,step;
};
queue<node> q;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		cnt=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			q.push({i,0});
			while(!q.empty()){
				node t=q.front();
				q.pop();
				if(v[i][t.zd]==0) v[i][t.zd]=t.step;
				for(int j=t.zd+1;j<=n;j++){
					if(a[j]-a[t.zd]<=d) q.push({j,t.step+1});
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				if(v[i][j]>=2){
					ll sum=0;
					q.push({i,0});
					while(!q.empty()){
						node t=q.front();
						q.pop();
						if(sum>2) break;
						if(t.zd==j&&t.step==v[i][j]) sum++;
						for(int j=t.zd+1;j<=n;j++){
							if(a[j]-a[t.zd]<=d) q.push({j,t.step+1});
						}
					}
					if(sum==2) cnt++;
				}
			}
			cout<<cnt<<"\n";	
		}
	}
}
