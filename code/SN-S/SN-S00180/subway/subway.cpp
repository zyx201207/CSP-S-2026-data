#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,st[500010],st1[500010];
struct wyy{
	int da;
	int db;
	int ti;
};
int arr[510][20010];
long long ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
//		for(int i=1;i<=m;i++){
//			cin>>st[i];
//		}
//		for(int i=1;i<=n;i++){
//			int k;
//			cin>>k;
//			for(int j=1;j<=2k;j++){
//				int a,t;
//				cin>>a>>t;
//				arr[i][a]=t;
//				
//			}
//		}
		while(q--){
			int x,y;
			ans=0;
			cin>>x>>y;
			ans+=st[x]+st[y];
			if(x==y){
				cout<<0;
				continue;
			}
			cout<<ans;
		}
			
	
}
