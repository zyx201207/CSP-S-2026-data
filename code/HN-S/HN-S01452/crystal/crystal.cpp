#include<bits/stdc++.h>
#define icezuikeai return 0;
#define int long long
using namespace std;
long long n,m,a[500005],sum=1,ans=-1,bg=1,b[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	memset(b,0,sizeof(b));
    if(n==1){
    	cout<<"1\n";
    	icezuikeai
	}
    for(int i=2;i<=n;i++){
    	b[i]=b[i-1]+(i-bg)*(a[i]-a[i-1]);
    	if(b[i]>m){
    		int cnt=0,t=0,lt;
    		for(int j=bg;(b[i]-cnt>m&&j<i-1);j++){
    			cnt+=(a[i]-a[j]);
    			t++;
    			lt=j+1;
			}
			if(b[i]-cnt>m){
				b[i]=0;
				sum=0;
				bg=i;
			}
			else {
				bg=lt;
			    b[i]=b[i]-cnt;
			    sum-=t;
			}
		}
        sum++;
    	ans=max(ans,sum);
	}
	cout<<ans<<'\n';
	icezuikeai
}
