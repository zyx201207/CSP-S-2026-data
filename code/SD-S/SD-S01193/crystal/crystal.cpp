#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll k,a[500005],b[500005],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	for(ll i=1,j=1;i<=n;i++){
		while(j<=i&&j<=n&&(i-j+1)*a[i]-(b[i]-b[j-1])>k)j++;
		if(j<=n)ans=max(ans,i-j+1);
	}
	cout<<ans;
} 
