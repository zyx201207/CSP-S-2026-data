#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],mx=1,sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		sum=0;
		int j;
		for(j=i-1;j>=1;j--){
			if(sum+a[i]-a[j]>m)break;
			sum+=a[i]-a[j];
		}
		mx=max(mx,i-j+0ll);
		//cout<<i<<':'<<j<<'\n';
	}
	cout<<mx;
	return 0;
}