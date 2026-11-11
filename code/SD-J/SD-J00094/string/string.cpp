#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char c[200005];
long long sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		if(c[l]!=c[r]){
			sum+=min(a[l],a[r]);
		}
		if(a[l]>=a[r]){
			a[l]=a[l]-a[r];
			a[r]=0;
		}else{
			a[r]=a[r]-a[l];
			a[l]=0;
		}
		if(a[l]==0)
			l++;
		if(a[r]==0)
			r--;
	}
	cout<<sum;
	return 0;
}
