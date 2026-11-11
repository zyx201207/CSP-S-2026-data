#include<bits/stdc++.h>
using namespace std;
const int N=500005;
typedef long long ll;
ll n,m,a[N],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	sort(a+1,a+n+1);
	ans=1;
	for(int i=2;i<=n;i++){
		ll sum=0,m1=m;
		for(int j=i;j>=1;j--)
		    if(a[i]-a[j]>m1) break;
		    else{
		    	m1-=(a[i]-a[j]);
		    	sum++;
			}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
} 
