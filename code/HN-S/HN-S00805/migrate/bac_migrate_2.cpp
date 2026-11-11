//15 03 2/6 0pts
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e6+5,N1=5000+5;
int c,x[N],n,d;
struct sub1{
	int cnt[N1],dis[N1];
	bool vis[N1];
	int solve(){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				dis[j]=0;
				cnt[j]=0;
				vis[j]=false;
			}
			queue<int> q;
			q.push(i);
			cerr<<"#"<<i<<endl;
			while(!q.empty()){
				int cur=q.front();
				q.pop();
				cerr<<"$"<<cur<<endl;
				int lt=cur,rt=n+1;
				while(lt+1<rt){
					int mid=(lt+rt)/2;
					if(x[mid]-x[cur]<=d){
						lt=mid;
					}
					else{
						rt=mid;
					}
				}
				for(int j=lt;j>=cur+1;j--){
					if(!vis[j]){
						q.push(j);
						vis[j]=true;
						dis[j]=dis[cur]+1;
						cerr<<"%"<<j<<" "<<dis[j]<<endl;
					}
					if(dis[j]==dis[cur]+1){
						cnt[j]++;
						cerr<<"^"<<j<<endl;
					}
				}
			}
			for(int j=i+1;j<=n;j++){
				if(cnt[j]==2){
					cerr<<"!"<<i<<" "<<j<<endl;
				}
				cerr<<"@"<<i<<" "<<j<<" "<<cnt[j]<<endl;
				ans+=cnt[j]==2;
			}
		}
		return ans;
	}
};
int help(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	if(n<=5000){
		sub1 tmp;
		return tmp.solve();
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cout<<help()<<endl;
	} 
	return 0;
}
/*
0 1
10 2
1 3 5 7 8 9 10 12 14 16

ans:16
*/
