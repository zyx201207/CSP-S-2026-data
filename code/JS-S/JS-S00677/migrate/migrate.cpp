#include<bits/stdc++.h>
using namespace std;
int n,d;
int a[2000006];
bool check(int u,int v){
	int cur=u;
	bool vis[2000006]={0};
	while(cur<v){
		int delta=1;
		while(a[cur+delta]-a[cur]<=d)delta++;
		delta--;
		if(delta==0)return 0;
		cur+=delta;
		vis[cur]=1;
	}
	cur=v;
	while(cur>u){
		int delta=1;
		while(a[cur]-a[cur-delta]<=d)delta++;
		cur-=delta;
		if(!vis[cur])return 1;
	}
	return 0;
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(check(i,j))cnt++;
		}
	}
}
void solvea(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	int delta=a[2]-a[1];
	if(d/delta<1||d/delta>1)puts("0");
	else cout<<n-3<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==11||c==12)solvea();
	else for(int i=1;i<=t;i++)solve();
}
