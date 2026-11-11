#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10000;
struct node{
	int x,t;
};

vector<node> vec[N];
//#define int long long
int n,m,d,q,a[N];
//int t[510][N];
map<int,long long> t[510];
void chu(int x){
	
	//for(int i=0;i<=m+1000;i++) t[x][i]=1e9;
	queue<int> que;
	que.push(x);
	t[x][x]=0;
	while(!que.empty()){
		int u=que.front();
		que.pop();
		for(int i=0;i<vec[u].size();i++){
			int v=vec[u][i].x,sum=t[x][u]+vec[u][i].t;
			if(sum<t[x][v]||(t[x][v]==0&&v!=x)){
				t[x][v]=sum;
				que.push(v);
			}
		}
	}
}
//un
int main(){
	ios::sync_with_stdio(0);//cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);

	int x;
	cin>>x>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			int x,t;
			cin>>x>>t;
			node v={x+1000,t},u={i,t};
			vec[i].push_back(v);
			vec[x+1000].push_back(u);
		}
	}
	for(int i=1;i<=n;i++){
		chu(i);
	}
	
	
	while(q--){
		int l,r;
		cin>>l>>r;
		long long sum=t[1][r+1000]+t[1][l+1000];
		for(int i=2;i<=n;i++){
			sum=min(sum,t[i][r+1000]+t[i][l+1000]);
		}
		sum+=a[l]+a[r];
		cout<<sum<<'\n';
	}
	return 0;
}

