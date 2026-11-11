#include<bits/stdc++.h>
using namespace std;
int n;
unsigned long long m;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	unsigned long long c=abs(a[2]-a[1]);
	int l=1,r=n;
	int ans;
	while(l<=r){
		unsigned long long mid=l+r>>1;
		if(c*(mid+1)*mid/2>m){
			r=mid-1;
		}else{
			l=mid+1;
			ans=mid;
		}
	}
	cout<<ans+1;
	return 0;
}