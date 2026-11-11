#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int v[500500];
struct Int{
	int x;
	Int(int xx=0){
		x=xx;
	}
	bool operator <(const Int& p)const{
		return v[x]>v[p.x];
	}
};
struct node{
	int x;
	vector<int>t;
	vector<int>v;
}a[1010];
ll c,n,m,d,q;
void bfs(int s,int t){
	priority_queue<Int>q;
	for(int i=1;i<=m;i++)v[i]=INT_MAX;
	v[s]=0;
	q.push(Int(s));
	while(!q.empty()){
		int x=q.top().x;q.pop();
//		cout<<v[x]<<" "<<v[q.top().x]<<"\n";
		for(int i=0;i<a[x].t.size();i++){
			int y=a[x].t[i];
			int yv=a[x].v[i];
			if(v[y]>v[x]+yv){
//				cout<<x<<" "<<y<<"\n";
				v[y]=yv+v[x];
				q.push(Int(y));
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i].x;
	for(int i=1;i<=n;i++){
		int k;cin>>k;int b1;
		if(c>=7&&c<=11){
			int x1,t1,x2,t2;
			cin>>x1>>t1>>x2>>t2;
			a[x1].t.push_back(x2);
			a[x2].t.push_back(x1);
			a[x1].v.push_back(t1+t2);
			a[x2].v.push_back(t1+t2);
		}
		else for(int j=1;j<=k;j++){
			int b,t;cin>>b>>t;
		}
	}
	for(int i=1;i<=q;i++){
		int s,t;cin>>s>>t;
		if(c>=7&&c<=11){
			int ans=a[s].x+a[t].x;
			bfs(s,t);
			cout<<ans+v[t]<<"\n";
		}
		else cout<<"0\n";
	}
}
