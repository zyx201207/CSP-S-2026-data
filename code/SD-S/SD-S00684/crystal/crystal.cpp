#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,cnt,ans,l=1,a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=5000){
		for(int i=n;i>=1;i--){
			cnt=0;
			for(int j=i-1;j>=1;j--){
				cnt+=a[i]-a[j];
				if(cnt<=m)ans=max(ans,i-j+1);
				else break;
			}
		}
		cout<<ans;
	}else{
		for(int i=1;i<=n;i++){
			cnt+=(a[i]-a[i-1])*(i-l);
			if(cnt<=m)ans=i-l+1;
			else{
				if((a[i]-a[i-1])*(i-l-1)<=a[i-1]-a[l])l++,cnt-=a[i]-a[l-1],ans=i-l+1;
				else break;
			}
		}
		cout<<ans;
	}
	return 0;
}
