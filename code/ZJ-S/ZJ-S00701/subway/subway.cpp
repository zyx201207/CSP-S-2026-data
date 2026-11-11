#include<bits/stdc++.h>
#define int long long
using namespace std;
int _,n,m,d,q,minn,u,v;
int dp[505][505],w[200005],k[505],pp[200005];
map <int,int>a[200005];
map <int,int>t[505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dp,0x3f,sizeof(dp));
	cin>>_>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		dp[i][i]=0;
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int ppp,pppp;
			cin>>ppp>>pppp;
			pp[ppp]++;
			a[ppp][pp[ppp]]=i;
			t[ppp][i]=pppp;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=pp[i];j++){
			for(int l=j+1;l<=pp[i];l++){
				int jj=a[i][j],ll=a[i][l];
				dp[jj][ll]=min(dp[jj][ll],t[i][jj]+t[i][ll]);
				dp[ll][jj]=min(dp[ll][jj],t[i][jj]+t[i][ll]);
			}
		}
	}
	for(int l=1;l<=n;l++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][l]+dp[l][j]);
			}
		}
	}
	for(int l=1;l<=n;l++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][l]+dp[l][j]);
			}
		}
	}
	while(q--){
		cin>>u>>v;
		minn=INT_MAX;
		for(int i=1;i<=pp[u];i++){
			for(int j=1;j<=pp[v];j++){
				minn=min(minn,dp[a[u][i]][a[v][j]]+t[u][a[u][i]]+t[v][a[v][j]]);			}
		}
		minn+=w[u]+w[v];
		cout<<minn<<"\n";
	}
	return 0;
}

/*

15:30
T1 DONE!\o\o\o\o\o SEE HIGH
   _
|_|_
 _| |
 
2= gotit

15:41
I hate tulun
subway=sbway
16:13 
never gonna give you up
CCF=Chinese Can Fly
2026CSPS RP++
I forgot to pay for my CSP-J
because I got an 1= last year
NBFLS nb!
luogu uid:582006 markkkk_NBFLS
NBFLS J2802 20 MCK
I am a chu 2 juruo
qiuguanzhu
IF I DON'T GET 1= THIS YEAR I WILL AFO lol
hope to get on the strange code list ovo
zhu hao
17:42
okkkkkk almost done 
yangli guo!!!
dayangli guo!!!
*/ 
