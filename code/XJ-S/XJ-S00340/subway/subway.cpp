#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[50001],k,a[50001][501],t[50001][501],ans=10e9,num;
int x[10001],y[10001];
vector <pair<int,int> > r(30,{0,0});
void find(int n){
	for(int i=0;i<=21;i++) r[i]={0,0};
	num=0;
	for(int j=1;j<=n;j++){
		for(int i=1;i<=k;i++){
			if(a[i][j]==n){
				r.push_back({i,t[i][j]});
				num++;
				//cout<<"aaa";
			}
		}
	}
}
void bfs(int i){
	long long time=w[x[i]];
	queue<pair<int,int> > du;
	find(x[i]);
	for(int i=0;i<num;i++){
		cout<<r[i].first<<" "<<r[i].second<<endl;
		//cout<<"aaa";
		//du.push({r[i].first,r[i].second+time+});
	}
	cout<<num;
}
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int j=1;j<=n;j++){
		cin>>k;
		for(int i=1;i<=k;i++){
			cin>>a[i][j]>>t[i][j];
			//cout<<1;
		}
	}
//	for(int j=1;j<=n;j++){
//		for(int i=1;i<=k;i++){
//			cout<<a[i][j]<<t[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	cout<<a[1][1];
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		bfs(i);
		cout<<ans;
	}
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2          
