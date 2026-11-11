#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],l=1,mx=1,now;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		now+=(a[i]-a[i-1])*(i-l);
		if(m>=now)mx=max(mx,i-l+1);
		else{
			while(m<now){
				now-=(a[i]-a[l]);
				l++;
			}
		}
	}
	cout<<mx;
	fclose(stdin);
	fclose(stdout);
}