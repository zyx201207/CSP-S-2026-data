#include<bits/stdc++.h>
using namespace std;
const int N=5e5+2;
int n,ans;
long long m,a[N],sum;
int main(){
	ios::sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=n-1,l=n-1;i>=0;sum-=max(i-l-1,0)*(a[i]-a[i-1]),i--){
		while(l>=0){
			sum+=a[i]-a[l];
			if(sum>m){
				sum-=a[i]-a[l];
				break;
			}
			l--;
		}
		ans=max(ans,i-l);
	}
	cout<<ans;
	return 0;
}
