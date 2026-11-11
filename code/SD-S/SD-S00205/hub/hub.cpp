#include<bits/stdc++.h>
#define int long long
using namespace std;
priority_queue<int>qp;
const int N=1e6;
vector<int>g[N];
queue<int>q;
int a[N];
void solve(){
    int n,k;
    cin>>n>>k;
    int cnt=1;
    for (int i=0;i<=n;i++)g[i].clear();
    for (int i=1;i<n;i++){
    int x,y;
	cin>>x>>y;
	g[x].push_back(y);
	g[y].push_back(x);
	if (g[x].size()>g[cnt].size()){
	cnt=x;	
	}	
	if (g[y].size()>g[cnt].size()){
	cnt=y;	
	}
	}
	q.push(cnt);
	a[cnt]=1;
    while (q.size()){
    int h=q.front();
	q.pop();
	for (auto t:g[h]){
	if (a[t])continue;
	else a[t]=a[h]+1;	
	}	
	}
	int ans=0;
	for (int i=1;i<=n;i++){
	if (a[i])
	qp.push(a[i]);
	} 
	for (int i=0;i<k;i++)qp.pop();
	cout<<qp.top()<<endl;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
	int T=1,C;
	cin>>C>>T;
    while (T--)solve();
	return 0;
}

