#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t,n,k,u,v,top,sum,lian;
int f[N],dep[N];
vector<int> vec[N];
int find(int x){
	return (x==f[x]?x:find(f[x]));
}
inline void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy){
		if(dep[fx]<dep[fy])swap(fx,fy);
		f[fy]=fx;
		dep[fx]=max(dep[fx],dep[fy]+1);
	}return ;
}
struct node{
	int u,lf,mid,dep;
	int yl;
	node(){}
	node(int a,int b,int c,int d,bool e){
		u=a,lf=b,mid=c,dep=d;
		yl=e;
	}
};
void bfs(int su,int slf,int smid,int sdep,int syl){
	queue<node> q;
	q.push(node(su,slf,smid,sdep,syl));
	while(!q.empty()){
		node now=q.front();
		q.pop();
		int u=now.u,lf=now.lf,mid=now.mid,dep=now.dep;
		int yl=now.yl;
//		cout<<"^"<<mid<<"#"<<u<<" "<<dep<<"->"<<yl<<"\n";
		bool nrl=1;
		for(int v:vec[u]){
			if(v==lf)continue;
			if(yl==1){
				if(dep==mid*2||lian>=2){
					sum++;dep=0;
					yl=2;
				}
			}else if(yl==0){
				if(dep==mid){
					sum++;dep=0;
					yl=1;lian++;
				}
			}else if(yl==2){
				if(dep==mid){
					dep--;
					sum++;
				}
			}nrl=0;
			q.push(node(v,u,mid,dep+1,yl));
		}if(yl<2&&nrl){
			if(dep>mid){
				sum++;
			}
		}
	}return ;
}
bool check(int mid){
	sum=0;lian=0;
	bfs(top,0,mid,0,0);
//	cout<<"mid="<<mid<<"\n";
//	cout<<"sum="<<sum<<"\n";
	return sum<=k;
}
void start(){
	cin>>n>>k;top=0;
	for(int i=1;i<=n;i++)vec[i].clear();
	for(int i=1;i<=n;i++)f[i]=i,dep[i]=1;
	for(int i=1;i<n;i++){
		cin>>u>>v;
		merge(u,v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}if(n==k){
		cout<<0<<'\n';
		return ;
	}for(int i=1;i<=n;i++){
		if(f[i]==i){
			top=i;break;
		}
	}int l=1,r=n-1,mid,ans=n-1;
	while(l<=r){
//		cout<<"#"<<l<<" "<<r<<"\n";
		mid=l+(r-l)/2;
		if(check(mid)){
			r=mid-1;
			ans=mid;
		}else{
			l=mid+1;
		}
	}cout<<ans<<'\n';
	return ;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		start();
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 3
1 2
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
