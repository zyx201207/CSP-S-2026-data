#include<bits/stdc++.h>

using namespace std;
int c,t;
int a[80000];
int mi[80000];
int o[80000];
bool fl[80000];
int bfs(int n,vector<int> v[]){
	int cntt=0;
	for(int i=1;i<=n;i++){
		fill(o,o+n+1,0);
		queue<int> q;
		q.push(i);
		int r=0;
		bool flag=1;
		fill(mi,mi+n+1,INT_MAX);
		fill(fl,fl+n+1,0);
		mi[i]=0;
//		cout <<'f'<< i<<' '<<mi[i]<<endl;
		do{
			flag=0;
			for(int i=1;i<=n;i++) if(mi[i]==INT_MAX) flag=1;
			int e=q.front();
			q.pop();
			for(int f:v[e]){
				if(fl[f]==0 || fl[e]==0) q.push(f);
				int u=mi[f];
//				cout << i<<"->"<<f<<":"<<mi[f]<<'/';
				mi[f]=min(mi[f],mi[e]+1);
				if(mi[e]+1==mi[f]){
					if(!fl[f] || !fl[e]) o[f]++;
					else o[f]+=o[e];
				}
//				cout<<mi[e]+1<<'('<<e<<')'<<endl;
//				if(mi[e]+1==mi[f]) cout << "+1"<<endl;
			}
			fl[e]=1;
			r++;
//			cout << 't'<<r<<' '<<q.size()<<' '<<q.empty()<<endl;
		}while(flag);
		for(int i=1;i<=n;i++) cntt+=(o[i]==2?1:0);
//		for(int i=1;i<=n;i++) cout << o[i]<<' ';
//		cout << '\n';
	}
	return cntt/2;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c>>t;
	while(t--){
		int n,d;
		cin >> n>>d;
		vector<int> v[80000];
		for(int i=0;i<n;i++) cin >> a[i];
		for(int i=0;i<n;i++){
//			cout << i<<endl;
			for(int j=i+1;j<n;j++){
//				cout << abs(a[j]-a[i])<<endl;
				if(abs(a[j]-a[i])<=d){
//					cout<<'y'<<endl;
					v[i+1].push_back(j+1);
					v[j+1].push_back(i+1);
				}
				else{
//					cout << 'n'<<endl;
					break;
				}
			}
		}
//		cout << 'e'<<endl;
//		for(int i=1;i<=n;i++){
//			int ui= v[i].size();
//			for(int j=0;j<ui;j++) cout << v[i+1][j]<<' ';
//			cout << '\n';
//		}
		cout << bfs(n,v)<<"\n";
	}
	return 0; 
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
