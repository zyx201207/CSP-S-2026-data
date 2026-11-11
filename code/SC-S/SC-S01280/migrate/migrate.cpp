#include <bits/stdc++.h>
using namespace std;
const int MAXN=305;
long long t[MAXN][MAXN],a[MAXN],n,d,ans;
bool v[MAXN];
long long tj[MAXN][MAXN];
void dfs(int start,int k,int now){
	if(t[start][k]>now){
		t[start][k]=now;
		tj[start][k]=1;
	}else if(t[start][k]==now){
		tj[start][k]++;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			if(a[i]-a[k]>=0){
				if(a[i]-a[k]<=d){
					v[i]=1;
					dfs(start,i,now+1);
					v[i]=0;
				}
			}else{
				if(a[k]-a[i]<=d){
					v[i]=1;
					dfs(start,i,now+1);
					v[i]=0;
				}
			}
		}
	}
} 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,q;
	cin>>c>>q;
	while(q--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				t[i][j]=1e9;
			}
		} 
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=(n+1)/2;i++){
			v[i]=1;
			dfs(i,i,0);
			memset(v,0,sizeof(v));
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ans+=(tj[i][j]%2==0&&tj[i][j]!=0);
			}
		} 
		memset(a,0,sizeof(a));
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}