#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int const N=5e5+10;
int n,m,a[N],ans,flag;
bool flaga=1,flagb=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) flaga=0;
		if(i==2) flag=a[2]-a[1];
		if(i>2&&(a[i]-a[i-1])!=flag) flagb=0;
	}	
	sort(a+1,a+n+1);
	if(flaga==1){
		for (int i=1;i<=n;i++)
			if(m-i>=0) m-=i,ans++;
		cout<<ans+1;
		return 0;
	}
	else if(flagb==1){
		for (int i=1;i<=n;i++)
			if(m-(i*flag)>=0) m-=(i*flag),ans++;
		cout<<ans+1;
		return 0;
	}
	for (int i=1;i<=n;i++){
		int cnt=0,mm=m;
		for (int j=i;j>=1;j--){
			if((mm-(a[i]-a[j]))>=0){
				mm-=(a[i]-a[j]);
				cnt++;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans; 
	return 0;
}
