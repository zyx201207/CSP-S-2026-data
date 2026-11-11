#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
int c,t,a[N],n,d,cnt,m;
void dfs(int x,int e,int k){
	if(x>e||k>m) return ;
	if(x==e&&k==m-1){
		cnt++;
		return ;
	}
	for(int i=1;i<=d;i++)
		dfs(x+i,e,k+1);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				cnt=0; m=j-i+1;
				dfs(i,j,1);
				if(cnt==2) ans++;
			}
		}
		cout<<ans<<"\n";
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
         