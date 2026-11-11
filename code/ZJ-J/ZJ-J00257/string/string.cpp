#include<bits/stdc++.h>
using namespace std;
int const N=2e5+5;
int n;
int l,r;
char c[N];
long long ans,minn;
long long a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	l=1,r=n;
	while(l<r){
		if(c[l]==c[r]){
			if(l+1==r) break;
			minn=min(a[l],a[r]);
			a[l]-=minn,a[r]-=minn;
			if(!a[l]) l++;
			if(!a[r]) r--;
		}else{
			if(a[l]<=a[r]) ans+=a[l],a[r]-=a[l++];
			else ans+=a[r],a[l]-=a[r--];
		}
	}
	cout<<ans;
	return 0;
}