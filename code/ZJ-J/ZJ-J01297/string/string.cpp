#include<bits/stdc++.h>
using namespace std;
long long n,a[201010],ans,l,r;char c[201010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n,r=n,l=1;
    for(long long i=1;i<=n;i++)cin>>a[i]>>c[i];
    while(l<r){
    	if(c[l]==c[r]){
    		if(a[l]==a[r])l++,r--;
    		else if(a[l]<a[r])a[r]-=a[l],l++;
    		else a[l]-=a[r],r--;
		}else{
			ans+=min(a[l],a[r]);
			if(a[l]==a[r])l++,r--;
    		else if(a[l]<a[r])a[r]-=a[l],l++;
    		else a[l]-=a[r],r--;
		}
	}cout<<ans;
	return 0;
}