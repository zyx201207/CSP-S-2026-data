#include<bits/stdc++.h>
using namespace std;
long long n,sum,m,a[500010],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum=a[i];
		for(int j=i;j<i+m;j++){
			sum&=a[j];
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
