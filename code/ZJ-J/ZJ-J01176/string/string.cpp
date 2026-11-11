#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	long long ans=0;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]<a[r]){
				a[r]-=a[l];
				a[l]=0;
				l++;
			}
			else if(a[l]==a[r]){
				a[l]=a[r]=0;
				l++,r--;
			}
			else{
				a[l]-=a[r];
				a[r]=0;
				r--;
			}
		}
		else{
			if(a[l]<a[r]){
				a[r]-=a[l];
				ans+=a[l];
				a[l]=0;
				l++;
			}
			else if(a[l]==a[r]){
				ans+=a[l];
				a[l]=a[r]=0;
				l++,r--;
			}
			else{
				a[l]-=a[r];
				ans+=a[r];
				a[r]=0;
				r--;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}