//what is the num of test points?idk
// no time of subway between stations in a line. interesting
// notice that n is small while k is large.hmm
// why is d important?
// what if we see all points on n a same dot? repetition
// oh i see how d matters. it makes sure that when we focus on n we do the search <=20. gg
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=501;
const int M=5e5+1;
const int D=21;
const ll INF=1e17+1949;
struct node{
	int a;
	ll t;
};
ll cost[N][N],w[M];
vector<node>lines[N];
vector<int>station2line[M];
int c,n,m,d,q;//c?哦若c==0是样例，可以拿来骗分，行 
ll find(int lin,int sta){
	int l=0,r=lines[lin].size()-1;
	int idx=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(lines[lin][mid].a==sta){
			idx=mid;
			break;
		}else if(lines[lin][mid].a>sta){
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	return lines[lin][idx].t;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cost[i][j]=INF;
		}
		cost[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a;
			ll t;
			cin>>a>>t;
			lines[i].push_back({a,t});
			station2line[a].push_back(i);
			for(int u:station2line[a]){
				if(u==i)continue;
				ll c=find(u,a)+t;
				cost[u][i]=min(cost[u][i],c); 
				cost[i][u]=cost[u][i];
			}
		}
	}
	for(int m=1;m<=n;m++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cost[i][j]=min(cost[i][m]+cost[m][j],cost[i][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=INF;
		int u_l1,u_l2;
		for(int l1:station2line[x]){
			for(int l2:station2line[y]){
				ll cur=cost[l1][l2];
				if(cur<ans){
					u_l1=l1;
					u_l2=l2;
					ans=cur;
				}
			}
		}
		cout<<ans+w[x]+w[y]+find(u_l1,x)+find(u_l2,y)<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2



*/
