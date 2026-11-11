#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100010],cnt;
int ans;
multiset<long long>st;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long num=0;
		for(int j=i+1;j<=n;j++){
			if(num+(a[j]-a[j-1])*(j-i)>m){
				ans=max(ans,j-i);
				break;
			}
			num+=(a[j]-a[j-1])*(j-i);
		}
	}
	cout<<ans;
	return 0;
}
