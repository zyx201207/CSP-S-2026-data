#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,w[N];
vector<int>a[N];
vector<int>t[N];
void solve(int x,int y){
	long long ans;
	ans+=w[x];ans+=w[y];
	if(x>y)swap(x,y);
	for(int i=1;i<=n;i++){
		for(int j=x;j<=y;j++){
			ans+=min(t[i][a[i][j]],t[i+1][a[i+1][j]]);
		}
	}
	cout<<ans<<endl;
}
   
int main(){
   freopen("subway.in","r",stdin);
   freopen("subway.out","w",stdout);
   cin>>c>>n>>m>>d>>q;
   for(int i=1;i<=m;i++)cin>>w[i];
   for(int k,i=1;i<=n;i++){
	   cin>>k;
	   for(int j=1;j<=k;j++){
		   cin>>a[i][j]>>t[i][a[i][j]];
	   }
   }
   for(int i=1;i<=q;i++){
	   int x,y;
	   cin>>x>>y;
	   solve(x,y);
   }
   return 0;
}
