#include<bits/stdc++.h>
#define N 2000005
#define ll long long
using namespace std;
int n;
int c,T;
ll a[N];
ll d;
int nxt[N];
int lst[N];
int vis[N];
int dp[N][2];
int L[N],R[N];
int main(){
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
	freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			L[i]=n+1,R[i]=0;
		}
		nxt[0]=1;
		for(int i=1;i<=n;i++){
			nxt[i]=nxt[i-1];
			while(nxt[i]<n and abs(a[nxt[i]+1]-a[i])<=d) nxt[i]++;
		}
		lst[n+1]=n;
		for(int i=n;i>=1;i--){
			lst[i]=lst[i+1];
			while(lst[i]>1 and abs(a[lst[i]-1]-a[i])<=d) lst[i]--;
			L[lst[i]]=min(L[lst[i]],i);
			R[lst[i]]=max(R[lst[i]],i);
		}
		for(int i=1;i<=n;i++){
			dp[i][0]=1;
			if(i>1 and R[i]==0) R[i]=R[i-1];
		}
		ll ans=0;
		if(n>5000){
			
		for(int i=1;i<=n;i++){
			int x=i;
			vector<int> p,b;
			while(1){
				p.push_back(x);
				if(x==n or nxt[x]==x) break;
				x=nxt[x];
			}
			for(auto j:p){
				vis[j]=1;
				
				if(j>i and (!b.size() or b.back()!=j-1)) b.push_back(j-1);
				b.push_back(j);
			}
			
			//sort(b.begin(),b.end());
			//b.erase(unique(b.begin(),b.end()),b.end());
			for(auto j:b){
				if(!vis[j]) vis[j]=2;
			}
			int pos=b.size()-1;
			for(int j=b.size()-1;j>=0;j--){
				int x=b[j];
				int l=L[x],r=R[x];
				if(j==0) l=x+1;
				if(l>r) continue;
				int len=r-l+1;
				while(pos>=1 and r<b[pos]){
					pos--;
					//len--;
				}
				while(pos>=1 and l<=b[pos] and b[pos]<=r){
					if(vis[x]==1){
						dp[x][0]+=dp[b[pos]][0];
						dp[x][1]+=dp[b[pos]][1];
					}
					else if(vis[x]==2){
						dp[x][1]+=dp[b[pos]][0];
					}
					pos--;
					len--;
				}
				
				if(vis[x]==1){
					dp[x][0]+=len;
				}
				else if(vis[x]==2){
					dp[x][1]+=len;
				}
			}
			ans+=dp[i][1];
			for(auto j:b){
				vis[j]=0;
				dp[j][0]=dp[j][1]=0;
				dp[j][0]=1;
			}
		}}
		else{
			
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[j][0]=1;
				vis[j]=0;
				dp[j][1]=0;
			}
			int x=i;
			vector<int> p,b;
			while(1){
				p.push_back(x);
				if(x==n or nxt[x]==x) break;
				x=nxt[x];
			}
			for(auto i:p){
				vis[i]=1;
				b.push_back(i);
				if(i>1) b.push_back(i-1);
			}
			sort(b.begin(),b.end());
			b.erase(unique(b.begin(),b.end()),b.end());
			for(auto j:b){
				if(!vis[j]) vis[j]=2;
			}
			for(int j=p.back();j>i;j--){
				int x=lst[j];
				x=max(x,i);
				if(vis[x]==1){
					dp[x][0]+=dp[j][0];
					dp[x][1]+=dp[j][1];
				}
				else if(vis[x]==2){
					dp[x][1]+=dp[j][0];
				}
			}
			ans+=dp[i][1];
		}}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 1
5 2
1 2 3 4 5
*/