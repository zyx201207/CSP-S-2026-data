//有一个jiankao so beautiful!
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010];
char c[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	int ans=0;
	int l=0,r=n-1;
	while(l<r){
		if(c[l]!=c[r])
			ans+=min(a[l],a[r]);
		if(a[l]<a[r])
		{
			a[r]-=a[l];
			l++;
		}
		else if(a[l]>a[r]){
			a[l]-=a[r];
			r--;
		}
		else{
			l++,r--;
		}
	}
	cout<<ans;
    return 0;
}
