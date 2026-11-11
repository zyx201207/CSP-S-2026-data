#include <bits/stdc++.h>
using namespace std;
long long n,m,c[500500],ans=1,dp[500500]={0,1},maxc=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++)  cin>>c[i],maxc=max(abs(c[i]),maxc);
	if(maxc<=100000000){
		sort(c+1,c+1+n);
		for(int i=2;i<=n;i++){
			dp[i]=1;
			long long o=m,ch=0,j=i;
			while(o>=ch+c[j]-c[j-1]&&j>1){
				dp[i]++;
				o=o-ch-c[j]+c[j-1];
				ch=ch+c[j]-c[j-1];
				j--;
			}
			if(ans<dp[i])  ans=i;
		}
		cout<<dp[ans];
	}else{
		cout<<n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
