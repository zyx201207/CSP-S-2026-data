#include<bits/stdc++.h>
using namespace std;
long long n,m,s=0,ans=-0x3f3f3f;
int a[100001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int k=m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		for(int j=i;j>=1;j--){
			if(k>=a[i]-a[j]){
				k-=a[i]-a[j];
				s++;
			}else break;
		}
		ans=max(ans,s);
		s=0;
		k=m;
	}
	cout<<ans;
	return 0;
}