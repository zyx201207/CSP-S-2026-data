#include<bits/stdc++.h>
using namespace std;
long long n,m;long long a[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		long long cu=0,cnt=0,j=i-1;
		while(j>=1){
			cu+=abs(a[i]-a[j]);
			cnt++;j--;
			if(cu>m){cnt--;break;}
		}
		ans=max(ans,cnt+1);
	}
	cout<<ans;
	return 0;
}
