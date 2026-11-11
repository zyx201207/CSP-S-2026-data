#include<bits/stdc++.h>
	
using namespace std;
const int N=5e5+10;
int n,m;
long long a[N],s[N];
long long ans=1;
void sol(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i-1,cd=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if((i-mid+1)*a[i]-s[i]+s[mid-1]<=m){
				r=mid-1;
				cd=mid;
			}
			else l=mid+1;
		}
		if(cd==0) continue;
		ans=max(ans,(long long)i-cd+1);
	}
	cout<<ans;
	return ;
}   
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int t=1;
	while(t--) sol();
	return 0;
}
//solve in 14:41:02