#include<bits/stdc++.h>
using namespace std;
long long a[500010],s[500010];
int main(){
	freopen("crystal.in","r",stdin);
  	freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,m,ans1=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)	cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)	s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++){
    	long long l=1,r=i,ans=i;
    	while(l<=r){
    		long long mid=(l+r)/2;
    		if((i-mid+1)*a[i]-(s[i]-s[mid-1])<=m)	r=mid-1,ans=mid;
    		else	l=mid+1;
		}
		ans1=max(ans1,i-ans+1);
	}
	cout<<ans1;
	return 0;
}

