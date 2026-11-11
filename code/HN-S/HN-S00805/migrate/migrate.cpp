//15 03 3/6 24pts
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e6+5,N1=5000+5;
int c,x[N],n,d;
struct sub1{
	int dis[N1][N1],fr[N1][N1];
	bool vis[N1][N1],tmp[N1];
	int solve(){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=fr[i][j]=vis[i][j]=0;
			}
			tmp[i]=0;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			queue<int> q;
			q.push(i);
//			cerr<<"#"<<i<<endl;
			while(!q.empty()){
				int cur=q.front();
				q.pop();
//				cerr<<"$"<<cur<<endl;
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
					if(!vis[i][j]){
						q.push(j);
						vis[i][j]=true;
						dis[i][j]=dis[i][cur]+1;
						fr[i][j]=cur;
//						cerr<<"%"<<j<<" "<<dis[j]<<endl;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
//				cerr<<"@"<<i<<" "<<j<<endl;
				if(!vis[i][j]){
//					cerr<<"$"<<endl;
					break;
				}
				for(int k=1;k<=n;k++){
					tmp[k]=false;
				}
				int pos=j;
				tmp[pos]=true;
				while(pos!=i){
					pos=fr[i][pos];
					tmp[pos]=true;
//					cerr<<"!"<<i<<" "<<pos<<endl;
				}
				tmp[i]=true;
				int cnt=0;
				for(int k=i+1;k<j;k++){
					if(!tmp[k]&&dis[i][k]+dis[k][j]==dis[i][j]){
						cnt++;
					}
				}
				if(cnt==1){
//					cerr<<"@"<<i<<" "<<j<<endl;
					ans++;
				}
			}
		}
		return ans;
	}
}tmp;
int help(){
//	cerr<<"%\n";
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
//	if(n<=5000){
//		sub1 tmp;
		return tmp.solve();
//	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	cin>>c>>t;
//	cerr<<"%\n";
	for(int i=1;i<=t;i++){//cerr<<"%\n";
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
//Any furry(furries)? 
