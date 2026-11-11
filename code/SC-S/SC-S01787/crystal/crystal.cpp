#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=9e5+7;
int dp[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    int n,m,w=0;
    cin>>n>>m;int frc=0;
    for(int i=1;i<=n;++i){
    	cin>>dp[i];
		if(dp[i]!=i) frc=1;
	} 
	int ywx=0;int su=0;
    for(int i=3;i<=7;++i) if(dp[i]-dp[i-1]!=dp[i-1]-dp[i-2]) ywx=1;
	if(frc==0) {
    	for(int i=1;i<=m;++i){
		    if(su+i>m){
		    	cout<<i<<'\n';
		    	return 0;
			}
    		su+=i;
    		
		}
	}
    if(ywx==0){
    	int noi=dp[2]-dp[1];
 
    	for(int i=1;i<=m;++i){
    		if(su+noi*i>=m){
    			cout<<i<<'\n';return 0;
			}
			su+=noi*i;
		}
	}
	
    
	stable_sort(dp+1,dp+n+1);
	
	for(int q=1;q<n;++q){
		 for(int i=q+1;i<=n;++i){int cnt=0;
		 for(int j=q;j<=i;++j){
			cnt+=dp[i]-dp[j];
			if(cnt>m) continue;
			if(cnt<=m) w=max(w,i-q+1);
		 }
	}
	}
	 
	cout<<w<<'\n';
	fclose(stdin);
	fclose(stdout);
}
