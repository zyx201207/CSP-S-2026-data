#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,ans;
long long m,a[maxn],s[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i-1;
		while(l<r){
			int mid=(l+r)/2;
			if(a[i]*(i-mid)-(s[i-1]-s[mid-1])>m)l=mid+1;
			else r=mid;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<endl;
	return 0;
} 
