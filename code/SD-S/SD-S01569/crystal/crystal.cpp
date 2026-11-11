#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],R,L,mx,r[500005],ans; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		r[i]=r[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		ll L=1,R=i;
		while(L<R){
			ll mid=(L+R)>>1;
			ll cyn=a[i]*(i-mid+1)-(r[i]-r[mid-1]);
			if(cyn<=m) R=mid;
			else L=mid+1;
		}
		ans=max(ans,i-R+1);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

