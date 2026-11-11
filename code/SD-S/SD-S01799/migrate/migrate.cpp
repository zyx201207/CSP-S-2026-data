#include<bits/stdc++.h>
#define FST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define int long long
#define ll long long
#define ull unsigned long long
//#define ls(x)(x<<1)
//#define rs(x)(x<<1|1)
#define lowbit(x)(x&-x)
using namespace std;
const int maxn=5e3+37;
int f[maxn][maxn],g[maxn][maxn];
int c,t;
int n;ll d;
int x[maxn];
queue<int> q;
bool inn[maxn];
queue<int> s1[maxn],s2[maxn];
int sum1[maxn];//sum2[maxn];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	FST;
	cin>>c>>t;
//	int t1=0;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			inn[i]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				g[i][j]=-1,f[i][j]=0;
			}
		}
		
		while(!q.empty())q.pop();//求g 步数min 
		g[1][1]=0;
		q.push(1);
		for(int i=2;i<=n;i++){
			g[i][i]=0;
			while((!q.empty())&&(x[i]-x[q.front()])>d)inn[q.front()]=0,q.pop();
			for(int j=1;j<i;j++){
				if(inn[j]){
					g[i][j]=1;continue;
				}
				if(q.empty()||g[q.front()][j]==-1)continue;
				g[i][j]=g[q.front()][j]+1;
			}
			q.push(i);inn[i]=1;
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<i;j++){
//				cout<<j<<"->"<<i<<": "<<g[i][j]<<endl;
//			}
//		}
		for(int i=1;i<=n;i++){//求f 方案数
			inn[i]=0,sum1[i]=0;
			while(!s1[i].empty())s1[i].pop();
			while(!s2[i].empty())s2[i].pop();
		}
		while(!q.empty())q.pop();
		for(int i=1;i<=n;i++){
			f[i][i]=1;//方案数 
			while((!q.empty())&&(x[i]-x[q.front()])>d)inn[q.front()]=0,q.pop();
			for(int j=1;j<i;j++){
				if(!s1[j].empty()){
					int z0=g[s1[j].front()][j];
					while((!s2[j].empty())&&g[s2[j].front()][j]==z0)s1[j].push(s2[j].front()),sum1[j]+=f[s2[j].front()][j],s2[j].pop();
				}
				while((!s1[j].empty())&&(x[i]-x[s1[j].front()])>d)sum1[j]-=f[s1[j].front()][j],s1[j].pop();
//				cout<<i<<"-"<<j<<" "<<s1[j].size()<<" "<<inn[j]<<endl;
				
//				cout<<"siz "<<s1[j].size()<<" "<<s2[j].size()<<endl;
				if(s1[j].empty()){
					if(!s2[j].empty()){
						int z1=g[s2[j].front()][j];
						while((!s2[j].empty())&&g[s2[j].front()][j]==z1)s1[j].push(s2[j].front()),sum1[j]+=f[s2[j].front()][j],s2[j].pop();
					}
				}
				while((!s1[j].empty())&&(x[i]-x[s1[j].front()])>d)sum1[j]-=f[s1[j].front()][j],s1[j].pop();
//				if(i==5&&j==1)cout<<"c51 :"<<s1[j].front()<<" "<<sum1[j]<<endl;
				if(inn[j]){
					f[i][j]=1;
				}else f[i][j]=sum1[j];
//				if((!s1[j].empty())&&g[s1[j].front()][j]==g[i][j])s1[j].push(i);
				s2[j].push(i);
				
			}
			q.push(i);inn[i]=1;
		}
		
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(f[i][j]==2)ans++;
//				cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
			}
		}
//		cout<<"num"<<++t1<<" "<<ans<<endl;
		cout<<ans<<endl;
	}
	return 0;
}


