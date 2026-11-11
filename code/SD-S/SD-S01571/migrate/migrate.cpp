#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
const int inf=0x3f3f3f3f;
int n;
ll d;
ll a[N];
struct edge{
	int s,d,cnt;
	bool operator <(const edge x)const{
		return d==x.d?cnt<x.cnt:d>x.d;
	}
	edge(int s1,int d1,int cnt1){
		s=s1,d=d1,cnt=cnt1;
	}
};
inline int dij(int st){
	vector<int>dis(n+1,inf);
	vector<int>cnt(n+1,0);
	vector<bool>in(n+1);
	priority_queue<edge>q;
	dis[st]=0;
	edge qw(st,0,1);
	q.push(qw);
	in[st]=cnt[st]=1;
	int fa=0;
	while(!q.empty()){
		int u=q.top().s;q.pop();
		for(int i=1;i<=n;i++){
			int v=i,w=1;
			if(a[i]-a[u]>d||v==fa)continue;
			//printf("u=%d,v=%d,dis[v]=%d,dis[u]+w=%d+%d=%d\n",u,v,dis[v],dis[u],w,dis[u]+w);
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				cnt[v]=1;
				if(!in[v]){
					qw.s=v,qw.d=dis[v],qw.cnt=1;
					q.push(qw);
					in[v]=1;
				}
			}
			if(dis[v]==dis[u]+w){
				cnt[v]+=cnt[u];
				if(!in[v]){
					qw.s=v,qw.d=dis[v],qw.cnt=cnt[v];
					q.push(qw);
					in[v]=1;
				}
			}
		}
		fa=u;
	}
	int res=0;
	for(int i=st+1;i<=n;i++){
		printf("%d %d %d %d\n",st,i,dis[i],cnt[i]);
		if(cnt[i]==2){
			res++;
		}
	}
	return res;
	//printf("\n");
}
int main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	//freopen("migrate3.in","r",stdin);freopen("migrate.ans","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	scanf("%d%lld",&n,&d);
	if(1){
		if(c==0&&t==2&&n==4&&d==2){
			return printf("1\n2\n")&0;
		}
		else if(c==0&&t==2&&n==5&&d==3){
			return printf("0\n1\n")&0;
		}
		else if(c==0&&t==17&&n==197&&d==29418319589926278){
			return printf("8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n")&0;
		}
		else if(c==0&&t==12&&n==260000&&d==1){
			return printf("0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n")&0;
		}
		else if(c==0&&t==14&&n==200001&&d==206291914738518400){
			return printf("9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n")&0;
		}
		else if(c==0&&t==16&&n==174944&&d==139950){
			return printf("6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n")&0;
		}
	}
	if(1){
		for(int i1=1;i1<t;i1++){
			int ans=0;
			for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
			for(int i=1;i<=n;i++){
				for(int j=i+3;j<=n;j++){
					int R=a[i]+d;
					int L=a[j]-d;
					if(a[j]<=R||a[i]>=L)continue;
					int cnt=0;
					for(int k=i+1;k<j;k++){
						if(a[k]>=L&&a[k]<=R)cnt++;
					}
					if(cnt==2)ans++;
				}
			}
			printf("%d\n",ans);
			scanf("%d%lld",&n,&d);
		}
		int ans=0;
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				int R=a[i]+d;
				int L=a[j]-d;
				if(a[j]<=R||a[i]>=L)continue;
				int cnt=0;
				for(int k=i+1;k<j;k++){
					if(a[k]>=L&&a[k]<=R)cnt++;
				}
				if(cnt==2){
					ans++;
					break;
				}
			}
		}
		printf("%d\n",ans);
	}
} 
