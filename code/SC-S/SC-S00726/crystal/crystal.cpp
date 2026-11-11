#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=-1e18;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n-1;i++)
		for(int j=i+1;j<=n;j++){
			long long t=j-1,sum=1,m1=m;
			while(m1>(a[j]-a[t])&&t>=0){
				m1-=a[j]-a[t];
				t--;
				sum++;
			}
			ans=max(ans,sum);
		}
	cout<<ans;
	return 0;
}