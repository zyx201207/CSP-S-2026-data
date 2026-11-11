#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,tot;
long long val_node[N];
long long change_line[505][505];
vector<pair<int,long long> >vec[N+500];
vector<int>to_line[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>val_node[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			change_line[i][j]=1e18+1;
			if(i==j) change_line[i][j]=0;
		}
	}
	tot=m;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		++tot;
		for(int j=1;j<=k;j++){
			int stati,tim;
			cin>>stati>>tim;
			vec[stati].push_back({tot,tim});
			vec[tot].push_back({stati,tim});
			for(auto x:vec[stati]){
				int st=x.first;
				long long val=x.second;
				if(st==tot) continue;
//				cout<<tot-m<<' '<<st-m<<" "<<tim+val<<"\n";
//				cout<<"sd:"<<tim+val<<"\n";
				change_line[min(tot-m,st-m)][max(tot-m,st-m)]=min(tim+val,change_line[min(tot-m,st-m)][max(tot-m,st-m)]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<change_line[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				change_line[i][j]=min(change_line[i][k]+change_line[k][j],change_line[i][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<change_line[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	while(q--){
		int xxx1,yyy1;
		long long ans=1e18;
		cin>>xxx1>>yyy1;
//		cout<<"xx:\n";
//		for(auto xx:vec[xxx1]) cout<<xx.first<<" "<<xx.second<<"\n";
//		cout<<"\nyy:\n";
//		for(auto yy:vec[yyy1]) cout<<yy.first<<" "<<yy.second<<"\n";
//		cout<<"\n";
		for(auto xx:vec[xxx1]){
			for(auto yy:vec[yyy1]){
				int x=xx.first-m,y=yy.first-m;
				ans=min(ans,min(change_line[x][y]+xx.second+yy.second+val_node[xxx1]+val_node[yyy1],
				change_line[y][x]+xx.second+yy.second+val_node[xxx1]+val_node[yyy1]));
//				cout<<x<<" "<<y<<' '<<ans<<"\n";
			}
		}
		cout<<ans<<" \n";
	}
	return 0;
} 
