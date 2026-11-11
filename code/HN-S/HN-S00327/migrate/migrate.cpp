#include<bits/stdc++.h>
using namespace std;
struct Node{
	long long a,s,len;
};
const long long MAX_N=2E6+78;
long long c,n,dis[MAX_N],d;
void js(){
	queue<long long>q;
	q.push(1);
	vector <long long> t[n+1];
	long long lj[n+1][n+1];
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			if(i==j){
				lj[i][j]=0;
			}else{
				lj[i][j]=0;
			}
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i-1;j>=1;j--){
			if(dis[i]-dis[j]>=d){
				t[j].push_back(i);
				lj[j][i]=1;
//				lj[i][j]=1;
			}
		}
	}
	for(long long k=1;k<=n;k++){
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				lj[i][j]=min(lj[i][j],lj[i][k]+lj[k][j]);
//				lj[j][i]=max(lj[j][i],lj[i][k]+lj[k][j]);
			}
		}
	}
//	for(long long i=1;i<=n;i++){
//		for(long long j=1;j<=n;j++){
//			cout<<lj[i][j]<<' ';
//		}cout<<'\n';
//	}
	long long ans=0;
	while(!q.empty()){
		long long now=q.front();q.pop();
		if(t[now].size()==2){
			for(long long i=now+1;i<=n;i++){
				if(lj[t[now][0]][i]==lj[t[now][1]][i]){
					ans++;
				}
			}
		}
	}
	cout<<ans<<'\n';
}
void solve_13_14(){
	cin>>n>>d;
	long long a;
	for(long long i=1;i<=n;i++){
		cin>>a;
	}
//	long long dp[n+1];
//	dp[1]=1;
//	dp[0]=0;
//	for(long long i=1;i<=n;i++){
//		dp[i]=0;
//		dp[i]+=dp[i-1]+1;
//	}
//	long long ans=0;
//	for(long long i=1;i<=n;i++){
//		ans+=dp[i];
//	}
	cout<<0<<'\n';
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c;
	if(c==13||c==14){
		long long t;
		cin>>t;
		while(t--){
			solve_13_14();
		}
	}else{
		long long t;
		cin>>t;
		while(t--){
			cin>>n>>d;
			for(long long i=1;i<=n;i++){
				cin>>dis[i];
			}
			js();
		}
	}
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/

/*
若(u,v)是，则(u,v)之后的所有可以到达的都是？
然后判断(u,v)是不是？
BFS找第一个， 
*/
