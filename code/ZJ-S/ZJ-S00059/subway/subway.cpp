#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,q;
int w[567890];
vector<int> a[567];
vector<int> t[567];
int k[567];int ans=0;
int sub[567890][3];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int cost=INT_MAX;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int s=0;
		for(int j=1;j<=k[i];j++){
			int aa,tt;
			cin>>aa>>tt;
			sub[aa][n]=tt;
		}
	}
	for(int i=1;i<=m;i++){
		if(sub[i][1]!=0&&sub[i][2]!=0){
			cost=min(cost,sub[i][1]+sub[i][2]);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=0;
		ans=w[x]+w[y];
		int cost1=INT_MAX,cost2=INT_MAX,cost3=INT_MAX,cost4=INT_MAX;
	if(sub[x][1]!=0&&sub[y][1]!=0)cost1=sub[x][1]+sub[y][1];
	if(sub[x][2]!=0&&sub[y][2]!=0)cost2=sub[x][2]+sub[y][2];
	if(sub[x][1]!=0&&sub[y][2]!=0)cost3=sub[x][1]+sub[y][2]+cost;
	if(sub[x][2]!=0&&sub[y][1]!=0)cost4=sub[x][2]+sub[y][1]+cost;
	ans+=min({cost1,cost2,cost3,cost4});
	cout<<ans<<"\n";
//	cout<<cost<<" "<<cost1<<" "<<cost2<<" "<<cost3<<" "<<cost4;
	}
		
	return 0;
} 
/*
0 2 3 0 2
1 1 1
2 1 1 3 1
2 2 1 3 1
1 2
2 3




*/
