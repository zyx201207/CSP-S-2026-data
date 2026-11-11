#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5,inf=1e18;
int c,t,n,d,a[N],ans=inf,res=0,cnt=0;
void dfs(int pos,int r,int m,int count){
	if(pos>=r){if(count<ans){ans=count;cnt=1;}else if(count==ans){cnt++;}return;}
	if(m+a[pos+1]-a[pos]<=d){dfs(pos+1,r,m+a[pos+1]-a[pos],count);}
	if(a[pos+1]-a[pos]<=d){dfs(pos+1,r,a[pos+1]-a[pos],count+1);}
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		res=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){cin>>a[i];}
		for(int l=1;l<=n;l++){
			for(int r=l;r<=n;r++){
				ans=inf;cnt=0;dfs(l,r,0,0);if(cnt==2){res++;}
			}
		}
		cout<<res<<endl;
	}
	return 0;
}