#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long a[N],ans,vis[N],sum[N];
void work(){
	long long n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	ans=0;
	queue<int >q;
	for(int i=1;i<=n;i++){
		q.push(i);
		for(int i=1;i<=n;i++){vis[i]=0;sum[i]=LLONG_MAX;}
		vis[i]=1,sum[i]=0;
		while(!q.empty()){
			long long u=q.front();
			q.pop();
			for(int j=u+1;j<=n;j++){
			//	cout<<u<<" "<<j<<"\n";
				if(a[j]-a[u]<=d){
					if(sum[u]+1<sum[j]){
						sum[j]=sum[u]+1;
						vis[j]=1;
						q.push(j);
					}else if(sum[u]==sum[j]-1){
						sum[j]+=sum[u];
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(sum[i]==2){
				ans++;
			}
		//	cout<<sum[i]<<" ";
		}
	//	cout<<"\n";
	}
	cout<<ans<<"\n";
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long T;
	cin>>T;
	cin>>T;
	while(T--){
		work();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
