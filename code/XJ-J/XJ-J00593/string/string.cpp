#include <bits/stdc++.h>
using namespace std;
long long a[200005],n;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n,ans=0;
	while(l<r){
		long long m=min(a[l],a[r]);
		if(c[l]!=c[r]){
			ans+=m;
		}
		a[l]-=m;
		if(a[l]==0) l++;
		a[r]-=m;
		if(a[r]==0) r--;
	}
	cout<<ans<<endl;
	return 0;
}