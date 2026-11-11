#include<bits/stdc++.h>
using namespace std;
const int N=6000;
int c,t;
int n,d,flag;
long long a[N],b[N][N],ans;
int mark[N];
void dfs(int x,int y,int l){
	if(x>y) return;
 	if(x==y){
 		flag=min(l,flag);
		mark[l]++;
		return;
	}
	for(int i=x+1;i<=n;i++){
		if(b[i][x]) dfs(i,y,l+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		if(n<=3){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=1;j<i;j++) b[i][j]=(a[i]-a[j]<=d?1:0);
		} 
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				memset(mark,0,sizeof mark);
				flag=n+1;
				dfs(i,j,0);
				if(mark[flag]==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
