#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,m,now,r=1,ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int l=1;l<=n;++l){
    	while(now+(a[r+1]-a[r])*(r-l+1)<=m&&r+1<=n)now+=(a[r+1]-a[r])*(r-l+1),r++;
    	ans=max(ans,r-l+1);
    	now-=a[l+1]-a[l];
	}
	cout<<ans;
	return 0;
}

