#include<bits/stdc++.h>
using namespace std;

const int N=500010;
int n,m;
int a[N],ans[N],st[N];
vector<int> v[N];

void solve(int x){
	for(int i=1;i<=m;i++) st[i]=0;
	stack<int> q;
	for(int i=x;i<=n;i++){
		if(st[a[i]]==0){
			st[a[i]]=1;
			q.push(a[i]);
		}
		else{
			while(q.top()!=a[i]){
				st[q.top()]=0;
				q.pop();
			}
		}
	}
	while(q.size()){
		ans[q.top()]++;
		q.pop();
	}
}
int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		solve(i);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}

