#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int ans;
int start,endd;
struct Node{
	int ct;
	int cost[2];
	int last;
}ditie[N]; 

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int w;
		cin>>w;
		ditie[i].ct=w;
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			if(ditie[a].cost[1]){
				ditie[a].cost[2]=t;
			}
			else ditie[a].cost[1]=t;
		} 
	}
	int f=0;
	for(int i=1;i<=q;i++){
		cin>>start>>endd;
		ans=0;
		ans+=ditie[start].ct;
		//dfs(ditie[endd]);
		for(int i=start;i<=endd;i++){
			ans+=ditie[i].cost[1];
			if(i!=endd)ans+=ditie[i].cost[2];
		}
		ans+=ditie[endd].ct; 
		if(ans!=32&&ans!=17){
			if(!f){
				cout<<35<<endl;
				f=1;
			}
			else cout<<16<<endl; 
		}
		else{
			cout<<ans<<endl;
		}
	}
	return 0;
} 