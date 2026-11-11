#include<bits/stdc++.h>
using namespace std;
long long int C,T,n,d,a[2000005],dp[5005],s[5005];
int main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C;
	cin>>T;
	if(C>=1&&C<=10){
		while(T--){
			long long int sum=0;
			cin>>n>>d;
			for(int i=1; i<=n; i++){
				cin>>a[i];
			}
			for(int i=1; i<=n-2; i++){
				memset(dp,0,sizeof(dp));
				memset(s,0,sizeof(s));
				long long int l=i;
				dp[i]=1;
				if(a[i+1]-a[i]>d)continue;
				dp[i+1]=1;
				s[i]=0;
				s[i+1]=1;
				for(int f=i+2; f<=n; f++){
					//if(a[f]-a[f-1]>d)break;
					while(a[f]-a[l]>d){
						l++;
					}
					if(l==f-1){
						dp[f]=dp[f-1];
						s[f]=s[f-1]+1;
					}
					else if(l==f-2){
						if(s[f-1]==s[f-2]){
							if(dp[f-1]==1&&dp[f-2]==1){
								dp[f]=2;
							}
							else{
								dp[f]=0;
							}
						}
						else{
							dp[f]=dp[f-2];
						}
						s[f]=s[f-2]+1;
					}
					else{
						if(s[l]==s[l+2]){
							dp[f]=0;
						}
						else if(s[l]==s[l+1]){
							if(dp[l]==1&&dp[l+1]==1){
								dp[f]=2;
							}
							else{
								dp[f]=0;
							}
						}
						else{
							dp[f]=dp[l];
						}
						s[f]=s[l]+1;
					}
					if(dp[f]==2){
						//cout<<i<<" "<<f<<endl;
						sum++;
					}
				}
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}