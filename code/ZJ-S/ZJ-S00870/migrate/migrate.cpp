#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
int c,t,n;
long long d,a[N],dp[N],f[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
    	cin>>n>>d;
    	for(int i=1;i<=n;i++)cin>>a[i];
    	if(c<=10){
    		int ans=0;
    		for(int i=1;i<=n;i++){
    			for(int j=i;j<=n;j++)dp[j]=f[j]=0;
    			int l=i,r=i;
    			f[i]=1;  
    			for(int j=i+1;j<=n;j++){
    				while(a[j]-a[l]>d)++l;
    				if(j==l)break;
    				dp[j]=dp[l]+1;
    				while(dp[r]<=dp[l]&&r<=j)r++;
    				r--;
    				if(r-l>1)f[j]=11451411;
    				else if(r==l)f[j]=f[l];
    				else f[j]=f[l]+f[r];
    				if(f[j]==2)++ans;
    				if(f[j]>2)f[i]=11451411;
				}
			}
			cout<<ans<<"\n";
		}else if(c==11||c==12){
			long long D=a[2]-a[1];
			long long k=d/D;
			if(k>=2)cout<<max(0ll,n-(2*k)+1)<<"\n";
			else cout<<"0\n";
		}
	}
	return 0;
}/*
分析一下T3，40pts的O(n^2)是好做的，8pts的等差数列也是好做的，这样+48pts就可以稳一等
严肃发现B性质属于C性质，但是我连B都不会打
CCF,I love you


*/