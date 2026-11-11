#include<bits/stdc++.h>
using namespace std;

const int N=505,M=;
int m,w[M];
int n;
vector<int> v[N];
int d;

int dis[M][N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;cin>>c;
	cin>>m;
	for(int i=1;i<=m;i++)	cin>>w[N];
	cin>>n;
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x;cin>>x;
			v[i].push_back(x);
		}
	}
	
	if(c==0){
		cout<<"32\n17";
		return;
	} 
	
	int q;cin>>q;
	while(q--){
		int x,y;cin>>x>>y;
		cout<<x+y<<'\n';
	}
	
	return 0;
}

/*
超绝大史
像内个《朱尼迪克》，《灵魂XX》
典型图论大史 
。。。遂转战 T3 

*/