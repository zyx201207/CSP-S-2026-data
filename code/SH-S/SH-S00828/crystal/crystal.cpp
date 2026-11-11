#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define I ios::sync_with_stdio(0);
#define AK cin.tie(0);
#define CSPS cout.tie(0);
#define handin 0
int n,m,a[514514],t[514514],p[514514],cost,ans,maxn;
signed main(){
	I AK CSPS
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=5000){
		for(int j=2;j<=n;j++){
			cost=0;
			for(int i=j;i<=n;i++){
				if(cost>m) break;
				ans=i-j+1;
				cost+=(a[i]-a[i-1])*ans;
			}
			maxn=max(ans,maxn);
			//cout<<ans<<endl;
		}
		cout<<maxn;
	}
	else if(m<=100000005){
		for(int i=-100;i<=100;i++){
			for(int j=2;j<=n;j++){
				if(a[j]==i){
					t[i+100]++;
				}
			}
		}
		for(int i=-100;i<=100;i++){
			p[i+101]=p[i+100]+t[i+101];
		}
		for(int i=-100;i<=100;i++){
			for(int j=i;j<=100;j++){
				if(cost+(p[j+101]-p[i-1+101])>m){
					ans=(p[j+101]-p[i-1+101])+1;
					break;
				}
				else{
					cost+=(p[j+101]-p[i-1+101]);
				}
				maxn=max(ans,maxn);
			}
		}
		cout<<maxn;
	}
	else{
		int l=0,r=m,mid;
		while(l<=r){
			mid=l+(r-l)/2;
			if((2*a[1]+mid*(a[2]-a[1])*mid/2)<=m){
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		cout<<l;
	}
	*/
	return 0;
}
