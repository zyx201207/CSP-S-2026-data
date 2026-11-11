#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int c,t,n,d,a[2000001],dp[2000001],dpx[2000001],ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int l=1;l<=t;l++){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			int k=i;
			dpx[i]=1;
			dp[i]=0;
			for(int j=i+1;j<=n;j++){
				while(a[i]-a[k]>d)	k++;
				int minn=0x3f3f3f3f3f3f3f3f;
				for(int m=k;m<i;m++){
					if(minn>dp[m])	dpx[i]=0,minn=dp[m];
					if(minn==dp[m])	dpx[i]+=dpx[m];
				}
				dp[i]=minn+1;
				if(dpx[i]==2)	ans++;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
9
1 5 6 9 11
i=2 j=1
(i-j-1)*dp[i-1]+(a[i]-a[i-1])
4
14:57 maybe T1
17:53 T2 ac but TLE subtask7 avg 1190ms
//freopen("crystal.in","r",stdin);
//freopen("crystal.out","w",stdout);
freopen("crystal.in.txt","r",stdin);
freopen("crystal.out.txt","w",stdout);
freopen("crystal.txt","r",stdin);
freopen("crystal.txt","w",stdout);
freopen("crystal1.in","r",stdin);
freopen("crystal.out","w",stdout);
freopen("crystal.im","r",stdin);
freopen("crystal.ont","w",stdout);
freopen("crysta.in","r",stdin);
freopen("crysta.out","w",stdout);
freopen("crystal1.in","r",stdin);
freopen("crystal.out","w",stdout);
freopen("crystal.in","w",stdin);
freopen("crystal.out","r",stdout);
#include<windows.h>
dlkfklsdnflsndflksdnfldkmfsdlkfmdlskfmdlskfmdsfusdfhdihf
//return 0
freopen("crystal.in","r",stdin)
freopen("crystal.out","w",stdout)
dwaadswdawdawdwsadwdwas
<><><><><><><><><><><><>
<><><><><><><><><><><><><>
*/
