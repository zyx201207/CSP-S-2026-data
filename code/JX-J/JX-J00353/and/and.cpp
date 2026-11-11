#include<bits/stdc++.h>
using namespace std;
int m,n,a[100005],cnt[32][100005],s[35],lenght,sum[32],len,num=-1,dp[100005];
void count(){
	for(int i=1;i<=n;i++){
		int x=a[i],l=0;
		while(x){
			l++;
			if(x&1){
				cnt[l][++sum[l]]=i;
				s[l]+=1;
			}
			x>>=1;
		}
		num=max(num,l);
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	count();
	for(int i=num;i>0;i--){
		if(s[i]>=m){
			len=s[i];
			lenght=i;
			break;
		}
	}
	dp[0]=a[cnt[lenght][1]];
	for(int i=1;i<=len;i++){
		for(int j=1;j<=i;j++){
			dp[j]=dp[j-1]&a[cnt[lenght][i]];
		}
	}
	cout<<dp[m];
	return 0;
}
