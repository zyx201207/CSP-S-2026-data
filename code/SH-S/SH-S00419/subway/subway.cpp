#include<bits/stdc++.h>
using namespace std;
int w[500050],a[1000010],t[1000010];
void bfs(){
	queue<int>q;
	q.push(l);
	long long sum=0;
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		int k;cin>>k;
		for(int i=0;i<k;i++){
			cin>>a[k]>>t[k];
		}
	}
	for(int i=0;i<q;i++){
		int l,r;cin>>l>>r;
		bfs(l,r);
	}
	cout<<0<<endl;
	return 0; 
}
