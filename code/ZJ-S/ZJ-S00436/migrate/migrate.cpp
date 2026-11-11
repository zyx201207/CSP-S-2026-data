#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
int c,t,n,ans,cnt;
ll d;
ll s[N];
ll dp[N];
void dfs(int v,int sum,int k){
	if(k<0)return;
	if(sum==v){
		cnt++;
		return;
	}
	for(int i=v+1;i<=n;i++){
		if(s[i]-s[v]<=d)dfs(i,sum,k-1);
		else return;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c<=10||c>=15){
		while(t--){
			cin>>n>>d;
			int ans=0;
			for(int i=1;i<=n;i++)cin>>s[i];
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					int k=0,pos=i;
					while(pos<j){
						k++;
						if(pos==upper_bound(s+1,s+n+1,s[pos]+d)-s-1){
							k=-1;
							break;
						}
						pos=upper_bound(s+1,s+n+1,s[pos]+d)-s-1;
						
					}
					if(k==-1)break;
					cnt=0;
					dfs(i,j,k);
					if(cnt==2)ans++;
				}
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
	if(c<=12){
		while(t--){
			cin>>n>>d;
			int ans=0;
			for(int i=1;i<=n;i++)cin>>s[i];
			int pos=d/(s[2]-s[1])*2-1;
			if(pos==-1||pos>n)cout<<"0\n";
			else cout<<n-pos+1<<"\n";
		}
		return 0;
	}
	else if(c<=14){
		while(t--){
			cin>>n>>d;
			int ans=0;
			for(int i=1;i<=n;i++)cin>>s[i];
			for(int i=1;i<=n;i++){
				int pos=upper_bound(s+1,s+n+1,s[i]+d)-s;
				for(int j=pos;j<=n;j++){
					cnt=0;
					for(int k=i+1;k<j;k++){
						if(s[k]-s[i]<=d&&s[j]-s[k]<=d)cnt++;
					}
					if(cnt==2)ans++;
				}
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
	return 0;
}
