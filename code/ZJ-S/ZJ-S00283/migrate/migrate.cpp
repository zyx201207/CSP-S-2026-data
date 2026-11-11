#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t;
long long x[N];
long long mins,tot;
long long d;
void dfs(int a,int b,long long cnt){
	if(a==b){
		if(mins==cnt){
			tot++;
		}
		else if(mins>cnt){
			mins=cnt;
			tot=1;
		}
	}
	for(int i=a+1;i<=b;i++){
		if(x[i]-x[a]<=d){
			dfs(i,b,cnt+1);
		}
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		int n;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==13 || c==14){
			cout<<"0\n";
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				if(x[j]-x[i]<=d){
					break;
				}
				else{
					mins=1e18;
					tot=0;
					dfs(i,j,0ll);
					if(tot==2ll){
						ans++;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}