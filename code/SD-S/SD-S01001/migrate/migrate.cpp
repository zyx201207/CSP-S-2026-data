#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	char c;
	int re=0,f=1;
	while (1){
		c=getchar();
		if ('0'<=c and c<='9')	break;
		if (c=='-'){
			f=-1;c='0';
			break;
		}
	}
	while (1){
		re=re*10+c-'0';
		c=getchar();
		if (!('0'<=c and c<='9'))	return re*f;
	}
}//ÏÈ´ò±©Á¦
const int N=1e6+5;
int n,d;
int a[N]; 
int nxt[N]; 
int ll1,ll2;
int ans,c,T;
int dp[N];
int s[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	while (T--){
		n=read(),d=read();
		ans=0,ll1=1,ll2=1;
		for (int i=1;i<=n;i++)
			a[i]=read();
		if (n>300){
			int ans=0;
			for (int i=4;i<=n;i++)
				if (dp[i]-dp[i-3]>d)	ans++;
			cout<<ans<<"\n";
			continue;
		}
		for (int i=1;i<=n;i++){
			memset(dp,63,sizeof(dp));
			memset(s,0,sizeof(s));
			dp[i]=0,s[i]=1;
			for (int j=i+1;j<=n;j++){
				for (int k=i;k<=j-1;k++)
					if (a[j]-a[k]<=d)
						dp[j]=min(dp[j],dp[k]+1);
				for (int k=i;k<=j-1;k++)
					if (a[j]-a[k]<=d and dp[k]+1==dp[j])
						s[j]=s[j]+s[k];
				if (s[j]==2)	ans++;
//				cout<<i<<" "<<j<<" "<<s[j]<<"\n";
			}
		}
		cout<<ans<<"\n";
	}
}

