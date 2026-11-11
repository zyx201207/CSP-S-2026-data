#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],front,back,mid,sum,flag,ans;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	front=1;
	back=n;
	sort(a+1,a+n+1);
	while(front<=back) {
		mid=front+(back-front)/2;
		sum=0;
		flag=0;
		for(int i=1; i<=mid; i++) {
			sum+=a[i];
		}
		if(a[mid]*mid-sum<=m) {
			flag=1;
		}
		for(int i=mid+1; i<=n; i++) {
			sum+=a[i]-a[i-mid];
			if(a[i]*mid-sum<=m) {
				flag=1;
			}
		}
		if(flag==1){
			front=mid+1;
			ans=mid;
		}else{
			back=mid-1;
		}
	}
	cout<<ans;
	return 0;
}