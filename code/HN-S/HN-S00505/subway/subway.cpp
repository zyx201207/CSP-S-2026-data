#include <bits/stdc++.h>
using namespace std;
const int N=500+5,M=2e4+5;//m为站点数,n为线路数 
int c,n,m,d,p;
int w[M];
//int t[M][N],a[N][M],num[M][N],len[M];
int t[M][N],a[N][M],num[M][N],len[M];
int v[M];
int ans=0;int q=0;

void moyi(int x,int y){//x为当前处在的节点 
	v[x] = 1;//标记走过的节点 
	
	if(q==1) return ;
	for(int i=1;i<=len[x];i++){
		int f=num[x][i];//现在寻找这一号线
		ans += t[f][x];//进入这一条线的站台 
		//cout<<"+"<<t[f][x]<<" "<<x<<" "<<endl;
		
		for(int i=1;a[f][i]!=0;i++){
			int now = a[f][i];//当前处于该站点
			 
			if(v[now] == 1){//当前站点被遍历过
				continue;//跳过 
			}
			
			ans += t[f][now];//进入该站点
			//cout<<"+"<<t[f][now]<<" "<<now<<" "<<endl;
			
			if(now == y){//若到达终点 
				ans += w[y];
				q=1;
				return ; 
			}
			moyi(now,y);//找总该站点前往终点的路线 
			if(q==1) return ;
			
			
			ans -= t[f][now];//跳出该站点
			//cout<<"-"<<t[f][now]<<" "<<now<<" "<<endl;
		}
		ans -= t[f][x];//跳出这一条线的站台 
		//cout<<"-"<<t[f][x]<<" "<<x<<" "<<endl;
	}
	return ;
}

int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c >>n >>m >>d >>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>a[i][j];//i号线可以到那些站点 
			cin>>t[i][ a[i][j] ];//i号线路到a站点的时间 
			len[ a[i][j] ]++;
			num[ a[i][j] ][ len[a[i][j]] ]=i;//a号站点可以到那些地铁站 
		}
	}
	for(int i=1;i<=p;i++){
		int x,y;
		cin>>x>>y;
		ans=w[x];q=0;
		for(int i=1;i<=m;i++) v[i]=0;
		moyi(x,y);
		cout<< ans <<endl;
	}
	return 0;
}/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7*/ 
