#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200010],cnt=0,fron,f=0,en,e=0,ans=0,dp[200010];
char c[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		dp[i]=dp[i-1]+a[i];
		cnt+=a[i];
	}
	fron=0;
	f=1;
	en=cnt+1;
	e=n;
	while(1){
		if(cnt%2==1){
			if(fron+1==en-1) break;
		}else{
			if(fron+1==en) break;
		}
		int y=a[f];
		if(fron+y>cnt/2) y=cnt/2-fron;
		fron+=y;
		int num=0,l=0;
		for(int i=e;i>0;i--){
			if(num>=y){
				if(num==y){
					e=i;
					en=en-y;
					ans+=l;
					break;
				}
				if(num>y){
					e=i+1;
					if(c[f]!=c[i+1]){
						l=l-(num-y);
					}
					en=en-y;
					ans+=l;
					break;
				}
			}
			if(dp[i]>=en){
				if(c[f]!=c[i]) l=l+(a[i]-(dp[i]-en+1));
				num=num+(a[i]-(dp[i]-en+1));
			}else{
				if(c[f]!=c[i]) l+=a[i];
				num+=a[i];
			}
		}
		f++;
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
