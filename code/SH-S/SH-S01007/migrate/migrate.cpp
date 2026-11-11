#include<bits/stdc++.h>//16s
using namespace std;
int n,C,t;
long long int d;
long long int c[5100][5100],sum[5100][5100],a[2100000];
map<long long int,int> m;
void dfs(int s,int x,int cnt){
	if(cnt<c[s][m[x]]){
		c[s][m[x]]=cnt;
		sum[s][m[x]]=1;
	}
	else if(cnt==c[s][m[x]]){
		sum[s][m[x]]++;
	}
	for(int i=1;i<=d;i++){
		if(m[x+i]!=0){
			dfs(s,x+i,cnt+1);
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>t;
	if(C==11||C==12){
		while(t--){
			long long int ans;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			long long int k=a[2]-a[1];
			if(d<2*k) cout<<0<<"\n";
			else{
				ans=n-2*(d/k)+1;
				cout<<max((long long int)0,ans)<<"\n";
			}
		} 
			
	}
	else{
		while(t--){
			memset(sum,0,sizeof sum);
			memset(c,0x3f,sizeof c);
			long long int ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
				m[a[i]]=i;
			}
			for(int i=1;i<=n-1;i++){
				dfs(i,a[i],0);
				for(int j=i+1;j<=n;j++){
					if(sum[i][j]==2){
						ans++;
					}
				}
			}
			cout<<ans<<"\n";
		} 
	}
	return 0;
}
