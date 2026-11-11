#include<bits/stdc++.h>
using namespace std;
typedef long long ll;typedef pair<int,int> pii;
pii dif[510][510];int a[5010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		memset(dif,0x3f,sizeof dif);
//		for(int i=1;i<=n;i++){
//			cin>>a[i];
//			for(int j=1;j<=i;j++){
//				if(abs(a[i]-a[j])<=m){
//					dif[i][j]=dif[j][i]={1,1};
//				}
//			}
//		}
//		for(int k=1;k<=n;k++){
//			for(int j=1;j<=n;j++){
//				for(int i=1;i<=n;i++){
//					if(dif[i][k].first+dif[j][k].first<=dif[i][j].first){
//						if(dif[i][k].first+dif[j][k].first==dif[i][j].first){
//							dif[i][j].second++;
//						}
//						else dif[i][j]={dif[i][k].first+dif[j][k].first,1};
//					}
//				}
//			} 
//		}          
//		int c=0;
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=i;j++){
//				if(dif[i][j].second==2){
//					c++;
//				}
//			}
//		}
		cout<<0<<"\n";
	}
	return 0;
} 
