#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,ans;
int a[N],c[N];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	
	for(int i=1;i<=n;i++){
		c[i]=a[i]-a[i-1];
	}
	
	int pre=0,tans=0,j=2,jbans=0;
	for(int i=2;i<=n;i++){
		while(j<=n){
			if(tans+c[j]*(j-i+1)>m)break;
			tans+=c[j]*(j-i+1);
			pre+=c[j];
			jbans++;
			j++;
		}
		ans=max(ans,jbans);
		
		tans-=pre;
		pre-=c[i];
		jbans--;
	}
	
	cout<<ans+1;
	return 0;
}
/*
5 8
-3 -1 2 2 7

5 5
1 2 4 8 9
*/