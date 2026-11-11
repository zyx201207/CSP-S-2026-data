#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,ans;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int l=1,r=n;
	while(l<r){
		int k;
		if(b[l]==b[r]){
			k=min(a[l],a[r]);
			a[l]-=k;
			a[r]-=k;
		}
		else if(a[l]>=a[r]){
			ans+=a[r];
			a[l]-=a[r];
			a[r]=0;
		}
		else{
			ans+=a[l];
			a[r]-=a[l];
			a[l]=0;
		}
		if(a[r]<=0){
			r--;
		}
		if(a[l]<=0){
			l++;
		}
	}
	cout<<ans;
	return 0;
}
