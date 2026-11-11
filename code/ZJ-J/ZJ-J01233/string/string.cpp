#include<bits/stdc++.h>
using namespace std;
long long n,ans,a[200005],l,r;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	l=1;r=n;
	while(l<r){
		if(c[l]==c[r]){
			long long t=min(a[l],a[r]);
			a[l]-=t;
			a[r]-=t;
			if(a[l]==0)l++;
			if(a[r]==0)r--;
		}else{
			long long t=min(a[l],a[r]);
			a[l]-=t;
			a[r]-=t;
			ans+=t;
			if(a[l]==0)l++;
			if(a[r]==0)r--;
		}
	}
	cout<<ans;
	return 0;
}
