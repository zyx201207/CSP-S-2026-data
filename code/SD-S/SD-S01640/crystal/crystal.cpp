#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
int n;
long long m,a[N],s[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i]; 
	sort(a+1,a+1+n); 
	
	for(int i=1;i<=n;i++){
		long long l=1,r=i;
		s[i]=s[i-1]+a[i];
		while(l<r){
			long long mid=(l+r)>>1;
			long long res=a[i]*(i-mid+1)-(s[i]-s[mid-1]);
			if(res>m) l=mid+1;
			else r=mid;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
