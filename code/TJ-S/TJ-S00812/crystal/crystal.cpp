#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[500005],l,r;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long cnt=0;
	for(r=1;r<=n;r++){
		cnt+=(a[r]-a[r-1])*(r-l);
		while(cnt>m){
			cnt-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
//lmy
