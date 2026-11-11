#include<bits/stdc++.h>
#define dbg(x) cerr<<"In Line "<<__LINE__<<" , "<<#x<<" = "<<x<<'\n';
using namespace std;

int main(){
	cin.tie(0)->sync_with_stdio(false);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;cin>>n;
	vector<int> a(n+1);
	vector<char> c(n+1);
	long long ans=0;
	
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r){
		int t=0;
		if(c[l]==c[r]){
			if(a[l]>a[r]){
				t=a[l]-a[r];a[l]=t;
				r--;
			}
			else if(a[l]<a[r]){
				t=a[r]-a[l];a[r]=t;
				l++;
			}
			else{
				l++,r--;
			}
		}
		else{
			if(a[l]>a[r]){
				t=a[l]-a[r];a[l]=t;
				ans+=a[r];
				r--;
			}
			else if(a[l]<a[r]){
				t=a[r]-a[l];a[r]=t;
				ans+=a[l];
				l++;
			}
			else{
				ans+=a[l];
				l++,r--;
			}
		}
	}
	cout<<ans;
	return 0;
} 
