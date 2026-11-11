#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+100;
const int inf=0x3f3f3f3f;
ll read(){
	ll x=0,f=1;
	char s=getchar();
	while(!isdigit(s)){
		if(s=='-')f=-1;
		s=getchar();
	}
	while(isdigit(s)){
		x=(x<<3)+(x<<1)+(s^48);
		s=getchar();
	}
	return x*f;
}
ll n[N];
int z[N];
int dis[N],dp[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int id,T;
	id=read(),T=read();
	while(T--){
		int a;ll d;
		a=read(),d=read();
		for(int i=1;i<=a;i++){
			n[i]=read();
		}
		queue<int>q;
		for(int i=1;i<=a;i++){
			while(!q.empty()&&n[i]-n[q.front()]>d)q.pop();
			if(q.empty())z[i]=i;
			else z[i]=q.front();
			q.push(i);
		}
		ll ans=0;
		for(int i=1;i<=a;i++){
			for(int j=i+1;j<=a;j++){
				dis[j]=inf;
				dp[j]=0;
			}
			dis[i]=0;dp[i]=1;
			for(int j=i+1;j<=a;j++){
				for(int k=max(z[j],i);k<j;k++){
					if(dp[j]>2)break;
					if(dis[k]+1>dis[j])break;
					else if(dis[k]+1==dis[j])dp[j]+=dp[k];
					else dis[j]=dis[k]+1,dp[j]=dp[k];
				}
				if(dp[j]==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}