#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>1;i--){
		long long pre=1,x=m;
		for(int j=i-1;j>=1;j--){
			if(a[i]==a[j])pre++;
			else if(x>=(a[i]-a[j])){
				x-=(a[i]-a[j]);
				pre++;
			}
			else if(x<a[i]-a[j])break;
		}
		ans=max(ans,pre);
	}
	cout<<ans;
	return 0;
}
