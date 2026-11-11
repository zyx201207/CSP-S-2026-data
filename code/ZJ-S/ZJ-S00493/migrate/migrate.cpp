#include<bits/stdc++.h>
using namespace std;
int c,t,n,f[2000005],num;
long long k,a[2000005],ans;
map<bool,int>check; 
void dfs(int x,int y,int step){
	if (x>y) return ;
	if (step>num || (step==num && x!=y)) return;
	if (x==y){
		if (step<num) num=step;
		f[step]++;
		return ;
	}
	for (int i=1;i<=k;i++){
		if(check[x+i]) dfs(x+i,y,step+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while (t--){
		cin>>n>>k;
		ans=0;
		check.clear();
		for (int i=1;i<=n;i++){
			cin>>a[i];
			check[a[i]]=1;
		} 
		for (int i=1;i<n-1;i++){
			for (int j=i+1;j<=n;j++){
				for (int k=1;k<=n;k++) f[k]=0;
				num=n;
				dfs(i,j,0);
				if (f[num]==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
}
