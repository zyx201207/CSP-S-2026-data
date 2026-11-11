#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
inline int input(){
	int s=0,w=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') w=-w;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<3)+(s<<1)+ch-'0';
		ch=getchar();
	}
	return s*w;
}
int c,T;
int x[N];
int t[N],dp[N];
queue<int>que;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=input(),T=input();
	while(T--){
		int n=input(),d=input();
		for(int i=1;i<=n;i++){
			x[i]=input();
			que.push(i);
			while(!que.empty()&&x[que.front()]+d<x[i]){
				t[que.front()]=i-1;
				que.pop();
			}
		}
		while(!que.empty()){
			t[que.front()]=n;
			que.pop();
		}
		int v=t[1],u=1;
		dp[1]=1;
		for(int i=2;i<=n;i++){
			if(!dp[i]) dp[i]=dp[u];
			if(t[i]!=v){
				dp[t[i]]=dp[u]*(v-i+1);
				v=t[i];
				u=i;
			}
		}
		int ans=0;
		for(int i=1,j=1;i<=n;i++){
			while(j<=n&&dp[j]/dp[i]<=2){
				if(dp[j]/dp[i]==2) ans++;
				j++;
			}
			if(j==n) j--;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*

*/
