#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+7;

int n,d;
int x[N];
namespace ImTrying1{
	
	int ans;
	struct node{
		int dis,cnt;
	}G[5050][5050];
	bool check(int st,int ed){
		return G[st][ed].cnt==2;
	}
	void solve1(){
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)G[i][j].dis=1e13,G[i][j].cnt=0;
		for(int i=1;i<=n;i++){
			int j=i+1;
			while(j<=n&&x[j]-x[i]<=d){
				G[i][j].dis=G[i][j].cnt=1;
				j++;
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(G[i][j].dis>G[i][k].dis+G[k][j].dis){
						G[i][j].dis=G[i][k].dis+G[k][j].dis;
						G[i][j].cnt=G[i][k].cnt*G[k][j].cnt;
					}
					else if(G[i][j].dis==G[i][k].dis+G[k][j].dis) G[i][j].cnt+=G[i][k].cnt*G[k][j].cnt;
				}
			}
		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				if(check(i,j)){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
}
namespace ImTrying2{
	void solve2(int D){
		if(D>d){
			cout<<"0\n";
			return ;
		}
		int max_jump=d/D;
		//cout<<n<<" "<<d<<" "<<max_jump<<" ";
		cout<<max(0ll,n-(2*max_jump-1))<<"\n";
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		bool flag=1;
		int D=-1;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i==1) continue;
			if(D==-1) D=x[i]-x[i-1];
			else if(D!=x[i]-x[i-1]) flag=0; 
		}
		if(n<=1000) ImTrying1::solve1();
		else if(flag) ImTrying2::solve2(D);
		
	}
	
	return 0;
}
