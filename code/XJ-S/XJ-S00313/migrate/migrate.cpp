#include<bits/stdc++.h>
#define Elysia return
#define u second
#define val first
//冬冬猫的代码
//T3
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const LL N=5010,M=2e6+10;
LL w[N][N];
LL mn[N][N];
LL c,t;
LL n,d;
LL x[M];
LL d1[N],d2[N];
bool vis[N];
bool solve(int s,int e){
//	queue<PII> q;
//	memset(d1,0x3f,sizeof(d1));
//	memset(d2,0x3f,sizeof(d2));
//	memset(vis,0,sizeof(vis));
//	for(int i=s+1;i<=n;i++){
//		if(w[s][i]!=1e9){
//			q.push({w[s][i],i});
//			d1[i]=w[s][i];
//		}
//	}
//	while(q.size()){
//		PII t=q.top();
//		q.pop();
//		vis[t.u]=true;
//		for(int i=t.u+1;i<=n;i++){
//			if(vis[i])continue;
//			if(d1[i]<t.val+w[s][i]){
//				q.push({t.val+w[s][i],i});
//				d1[i]=t.val+w[s][i];				
//			}
//		}
//	}
//	memset(vis,0,sizeof(vis));
//	for(int i=e+1;i>=1;i--){
//		if(w[e][i]!=1e9){
//			q.push({w[i][e],i});
//			d2[i]=w[i][e];
//		}
//	}
//	while(q.size()){
//		PII t=q.top();
//		q.pop();
//		vis[t.u]=true;
//		for(int i=t.u-1;i>=1;i--){
//			if(vis[i])continue;
//			if(d2[i]<t.val+w[i][e]){
//				q.push({t.val+w[i][e],i});
//				d2[i]=t.val+w[i][e];				
//			}
//		}
//	}	
	int cnt=0;
	for(int i=s+1;i<=e-1;i++){
		if(mn[s][i]+mn[i][e]==mn[s][e])cnt++;
		if(cnt>2) Elysia false;
	}
	
	if(cnt==2)Elysia true;
	Elysia false;
}

int s[N];

bool solve(int u,int v,int k){
	
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	std::cin.tie(false);
	std::cout.tie(false);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(c==13||c==14||c==0||c==11||c==12){
			for(int i=1;i<=n;i++) cin>>x[i];
			if(c==11||c==12){
				if(d<=(x[2]-x[1])){
					cout<<0<<"\n";
				}
				else if(x[2]-x[1]<=1e9&&d<=1e9){
					if(n-d/(x[2]-x[1])-(d/(x[2]-x[1])-1)<0) cout<<0<<"\n";
					else cout<<n-d/(x[2]-x[1])-(d/(x[2]-x[1])-1)<<"\n";
				}
				else{
					if(d%(x[2]-x[1])!=0||d<=(x[2]-x[1])){
						cout<<0<<"\n";
					}
					else{
						if(n-d/(x[2]-x[1])-(d/(x[2]-x[1])-1)<0) cout<<0<<"\n";
						else cout<<n-d/(x[2]-x[1])-((d/x[2]-x[1])-2+1)<<"\n";
					}
				}
			}
			if(c==13||c==14) cout<<0<<"\n";
			continue;
		} 
		for(int i=1;i<=n;i++){
			cin>>x[i];
			s[i]=x[i]-x[i-1]+s[i-1];
			for(int j=1;j<=n;j++) w[i][j]=mn[i][j]=1e9;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=1;k<=j-i+1;k++){
					if(solve(i,j,k)){
						mn[i][j]=k;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				w[i][j]=mn[i][j]=x[j]-x[i];
			}
		}
		
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=i+1;k<=j-1;k++){
					mn[i][j]=min(mn[i][j],mn[i][k]+mn[k][j]);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(solve(i,j)){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	Elysia 0;
}
/*
这个暴力好像要好些很多 

额 特殊性质B 就是1到n的距离<=d
那1 2 3 4 5……
1 2不行
1 2 3(1 3, 1_2,2_3) 2个
1 2 3 4(1_4,1_2,2_4,1_3,3_4) 那之后的都不行了 
*/
