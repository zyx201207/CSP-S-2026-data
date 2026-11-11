#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}a[n+1]=1e18+1;
	sort(a+1,a+n+1);
	long long l=1,r=1,ans=1,f=0;
	while(r<=n && l<=r){
		if(f<=m)
		{
			r++;
			f+=(a[r]-a[r-1])*(r-l);			
		}
		if(f>m)
		{
			f-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
