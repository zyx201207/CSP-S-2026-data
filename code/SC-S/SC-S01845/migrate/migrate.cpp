#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=2e6+2;
int c,t;
ll x[MAXN];//编号 

vector<int>e1[MAXN];
ll cnt1[302],num1[302];//cnt表示到i的最短路长度，num表示到i的最短路数量 
bool flag1[302];//求没求出最短路 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		int n;
		ll d;
		//in
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%lld",&x[i]);
			
		//solve
		if(c<=10){
			ll ans=0;
			//dif
			for(int i=1;i<=n;i++) e1[i].clear();
			//build
			for(int i=1;i<n;i++)
				for(int j=i+1;j<=n&&x[j]-x[i]<=d;j++)
					e1[i].push_back(j);
			for(int s=1;s<n;s++){
				memset(cnt1,0x3f,sizeof(cnt1));
				memset(num1,0,sizeof(num1));
				memset(flag1,0,sizeof(flag1));
				cnt1[s]=0;
				num1[s]=1;
				for(int step=1;step<=n-s+1;step++){
					ll min_w=0x3f3f3f3f3f3f3f3f,u;
					for(int i=s;i<=n;i++){
						if(cnt1[i]<min_w&&flag1[i]==0){
							min_w=cnt1[i];
							u=i;
						}
					}
					flag1[u]=1;
					for(int v:e1[u]){
						if(cnt1[v]>cnt1[u]+1){
							cnt1[v]=cnt1[u]+1;
							num1[v]=num1[u];
						}else if(cnt1[v]==cnt1[u]+1){
							num1[v]+=num1[u];
						}
					}
				}
				
				for(int i=s+1;i<=n;i++){
					if(num1[i]==2) ans++;
				}
			}
			printf("%lld",ans);
	    }
		if(c==11||c==12){
			ll cnt=x[2]-x[1];//公差 
			ll num=d/cnt;//表示一次最多飞过多少个工差 
			if(num<=1) printf("0"); //一次只能飞一个岛，不存在 双径岛屿对
			else{
				printf("%d",max((ll)0,n-(num+num)+1)); 
				// 存在 双径岛屿对 且每次飞过2*num个岛 
			} 
		}
//		if(c==0||c==13||c==14){
//			if(n<3) printf("0");
//			else{
//				int l=1,r=4; 区间l,r之间不含l，r只有两个点满足可以两步到 
//				for(int i=) 
//			}
//			
//		}
		printf("\n");
	}
}