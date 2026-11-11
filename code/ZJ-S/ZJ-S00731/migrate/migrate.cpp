#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n;
long long d;
long long dp[N],a[N],fa[N],son[N];
long long suf[N],pre[N];
void solve1(){//1~6
	int ans=0; 
	//for(int i=1;i<=n;i++)cout<<a[i];
	int p=0;
	deque<int>q;
	memset(dp,0x3f,sizeof dp);
	memset(fa,-1,sizeof fa);
	memset(son,-1,sizeof son);
	memset(pre,0,sizeof pre);
	memset(suf,0,sizeof suf);
	dp[1]=0;
	q.push_back(1);
	for(int i=2;i<=n;i++){
			//cout<<a[i];
			while(!q.empty()&&a[i]-a[q.back()]>d){
				q.pop_back();
			}
			if(q.empty()){
				q.push_back(i),p++,dp[i]=p*1e8;
				continue;
			}
			int e1=q.back(),e2=n+1;q.pop_back();
			if(!q.empty()){
				e2=q.back();
				q.pop_back();
			}
			if(dp[e1]!=dp[e2]){
				fa[i]=e1;
				son[e1]=i;
			}
			else{
				fa[i]=-1;
				son[e1]=-1;
			}
			if(e2!=n+1)q.push_back(e2);
			q.push_back(e1);
			
			dp[i]=dp[q.back()]+1;
			while(!q.empty()&&dp[q.front()]>dp[i]){
				q.pop_front();
			}
			q.push_front(i);
		}
	for(int i=2;i<=n;i++){
		if(fa[i]!=-1){
			pre[i]=pre[i-1]+1;
		}
	}
	for(int i=n;i>=1;i--){
		if(son[i]!=-1){
			suf[i]=suf[i+1]+1;
		}
	}
	for(int i=1;i<=n-3;i++){
		//cout<<a[i+3]-a[i]<<' '<<d<<'\n';
		if(a[i+3]-a[i]>d&&a[i+2]-a[i]<=d&&a[i+3]-a[i+1]<=d){
			ans+=1*(pre[i]+1)*(suf[i+3]+1);
			//cout<<suf[i+3];
		}
	}
	cout<<ans<<'\n';
	
}

void solve0(){
	//cout<<n;
	if(d==2)cout<<max(0,n-3);
	else cout<<0;
	cout<<'\n';
}
int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		//cout<<n<<' ';
		bool flag=1;
		for(int i=1;i<=n;i++){
			//int k;
			cin>>a[i];
			//cout<<k;
			if(i!=1&&a[i]-a[i-1]!=1)flag=0;
		}
		if(flag)solve0();
		else solve1();
	}
}
