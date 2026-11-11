//long long
//清空文件夹其他文件
//freopen!!!文件名+别注释 
//线段树开4倍，双向边开2倍，不同点组开总点数倍，小心N的+10和循环上界，小心越界，未定义行为!!! 
//别用endl 
//考虑各种特例 
//初始化问题!! 
//多测清空!!!
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int N=2e6+10;

int cnum,T;
int n;
long long a[N];
long long d;
int mxp[N],mxs[N];

int head[N];
struct Edge{
	int next,to;
}e[N<<1];

int tote=0;
void add_edge(int from,int to){
	++tote;
	e[tote].next=head[from];
	head[from]=tote;
	e[tote].to=to;
	return ;
}

int ef(long long x){
	int l=1,r=n,mid;
	while(l<r){
		mid=(l+r+1)>>1;
		if(a[mid]>x) r=mid-1;
		else l=mid;
	}
	return l;
}

int h,t;
int q[N];
int dis[N];
int num[N];

long long bfs(int st){
	
	for(int i=st;i<=n;++i){
		dis[i]=0x3f3f3f3f;
		num[i]=0;
	}
	
	h=t=0;
	q[t++]=st;
	dis[st]=0;
	
	while(t-h){
		int nw=q[h++];
		for(int i=head[nw];i;i=e[i].next){
			int v=e[i].to;
			if(dis[v]>dis[nw]+1){
				dis[v]=dis[nw]+1;
				num[v]=1;
				q[t++]=v;
			}
			else if(dis[v]==dis[nw]+1){
				++num[v];
			}
		}
//	cout<<num[3]<<' ';
	}
	
//	cout<<num[3]<<'\n';
	
	long long ans=0;
	for(int i=st+1;i<=n;++i){
		if(dis[i]!=0x3f3f3f3f&&num[i]==2){
			++ans;
		}
	}
	
	return ans;
}

int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>cnum>>T;
	
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		if(n==1){
			cout<<0<<'\n';
			continue;
		}
		if(cnum==11||cnum==12){
			long long dd=a[2]-a[1];
			if(d<(dd<<1)){
				cout<<0<<'\n';
				continue;
			}
			else{
				long long num=d/dd;
				if(num>=n){
					cout<<0<<'\n';
					continue;
				}
				cout<<max(0ll,n-(num<<1)+1)<<'\n';
				continue;
			}
		}
		if(cnum==13||cnum==14){
			long long ans=0;
			for(int i=1;i<=n;++i){
				int nx1=ef(a[i]+d);
				if(nx1<=i+1) continue;
//				int nx11=ef(a[nx1]+d);
				int nx22=ef(a[nx1-1]+d);
				int nx33=ef(a[nx1-2]+d);
				ans+=1ll*(nx22-nx33);
			}
			cout<<ans<<'\n';
			continue;
		}
		
		tote=0;
		for(int i=0;i<=n;++i){
			head[i]=0;
		}
		
		for(int i=1;i<=n;++i){
			int nx1=ef(a[i]+d);
			for(int j=i+1;j<=nx1;++j){
				add_edge(i,j);
			}
		}
		
		long long ans=0;
		for(int i=1;i<=n;++i){
			ans+=bfs(i);
//			cout<<ans<<' ';
		}
		
		cout<<ans<<'\n';
		
	}
	
	return 0;
} 
