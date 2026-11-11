#include <bits/stdc++.h>
using namespace std;
long long ans=0;
long long a[1000005];
char c[1000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie();
	cout.tie();
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		long long t=min(a[l],a[r]);		
	    if(c[l]!=c[r])
			ans+=t;
		a[l]-=t;
		a[r]-=t;
        if(!a[l])
            l++;
        if(!a[r])
            r--;
	}
	cout<<ans;
	return 0;
}
