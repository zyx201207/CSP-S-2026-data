#include <bits/stdc++.h>

#define fr for
#define int long long

using namespace std;

inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0'||ch>'9'){
		f|=ch=='-';ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return f?-x:x;
}
/*
d这么小有什么用呢

并且最多有 500 条线，有啥用呢
 
 只算步行时间，也就是说坐地铁没有花费
 
 然后显然同一条线可以合并
 
 点数：还是 O(m) 的
 
 注意到每个站最多有 20 条地铁，有什么用呢
 
 这说明我们可以只保留地铁线路的点跑floyd
 
 然后呢，询问枚举坐的地铁
 
 等我再理清一下思路，45分开写
 
 似乎不彳亍
 
 女子白勺 
 
 应该是会了 
 
 15:51 100pts
*/
const int N=5e5+7;

vector<int>sbw[N],w[N];
//每个点到达的 地铁 ，以及要走的距离 
int d[507][507];

int W[N];//作用相当于滚木

vector<int>a[507],t[507]; 

//算一下复杂度
//时间：O(Kd+n^3+qd^2) ，空间 O(K+md+n^2) 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	double st=clock();
	read();
	int n=read(),m=read();//注意m是地铁站数量 
	read();int q=read();
	fr(int i=1;i<=m;i++)W[i]=read();
//	fr(int i=1;i<=m;i++){
//		sbw[i].reserve(21);
//		w[i].reserve(21);
//	} 
	fr(int i=1;i<=n;i++){
		int k=read();
//		a[i].reserve(k+2);t[i].reserve(k+2);
		while(k--){
			int x=read(),y=read();
			a[i].push_back(x);t[i].push_back(y);
			sbw[x].push_back(i);w[x].push_back(y);
		}
	}
	memset(d,0x3f,sizeof d);
	fr(int i=1;i<=n;i++)d[i][i]=0;
	
	fr(int i=1;i<=n;i++){
		fr(int j=0;j<a[i].size();j++){
			int sta=a[i][j],dis=t[i][j];
			fr(int k=0;k<sbw[sta].size();k++){
				int l=sbw[sta][k],dis2=w[sta][k];
				d[i][l]=min(d[i][l],dis+dis2);
				d[l][i]=min(d[l][i],dis+dis2);
			}
		}
	}
	fr(int k=1;k<=n;k++){
		fr(int i=1;i<=n;i++){
			fr(int j=1;j<=n;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	while(q--){
		int x=read(),y=read();
		int ans=1e18;
		fr(int i=0;i<sbw[x].size();i++){
			int u=sbw[x][i],d1=w[x][i];
			fr(int j=0;j<sbw[y].size();j++){
				int v=sbw[y][j],d2=w[y][j];
				ans=min(ans,d[u][v]+d1+d2);
			}
		}
		printf("%lld\n",ans+W[x]+W[y]);
	}
	
//	cerr<<clock()-st;
	return 0;
}
/*
By C_0_a4S,Luogu_uid=1424067

都 2026 年了，我怎么还在考 CSP？
            ###################
         ############\\############
       ##############\\##############
      ################################
     #######\\\\\\\\\\\\\\\\\\\\#######
    ####################################
    #############\\\\\\\\\##############
    #############\#######\##############
    #############\\\\\\\\\##############
    ####################################
     #######\\\\\\\\\\\\\\\\\\\\#######
      ######\##################\######
        ###########\\\\\\###########
          ########\######\##\#####
            ######\######\\\\###
             #################
 Oct31==Dec25?

//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);
//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);
//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);
//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);
//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);
//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);
//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);//freopen("crystal.in","r",stdin);

大样例7跑了0.75 秒，但是我复杂度是对的，别**给我卡常了/fn 
*/

