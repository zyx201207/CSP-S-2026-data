#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
using ll=long long;
int c;
ll x[maxn],d,nxt[maxn],jump;
int dfs(int s,int end,int rest){
	if(rest>=d){
		return 0;
	}
	if(s==end){
		return 1;
	}
	//cout<<s<<endl;
	int res=0;
	for(int i=s+1;i<=end;i++){
		if(x[i]-x[s]>d)break;
		res+=dfs(i,end,rest+d-(x[i]-x[s]));
	}
	return res;
}
void solveA(){
	int n;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	ll base=d/(x[2]-x[1]);
	if(base==0||base==1){
		cout<<0<<'\n'; 
		return;
	}
	ll k=2*base-1;
	if(n<k){
		cout<<0<<'\n'; 
		return;
	}
	cout<<n-k<<'\n';
}
void solveBCminn(){
	int n,ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	int k=1; 
	for(int i=1;i<=n;i++){
		while(x[k]-x[i]<=d && k<=n){
			k++;
		}
		nxt[i]=k-1;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			if(x[j]-x[i]>d){
				int u=dfs(i,j,0);
				if(u==2){
					ans++;
				}
			}
		}
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	cin>>c>>t;
	while(t--){
		if(c==11 || c==12){
			solveA();
		}else{
			solveBCminn();
		}
	}
	return 0;
}