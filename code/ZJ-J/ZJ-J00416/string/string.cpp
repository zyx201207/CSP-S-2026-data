#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,len,ans;
int a[200005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	int l=1,r=n,cnt=0;
	while(l<=r){
		if(c[l]==c[r]){
			if(a[l]<=a[r]){
				a[r]-=a[l];
				cnt+=a[l];
				a[l]=0;
				l++;
				if(a[r]==0){
					r--;
				}
			}
			else{
				a[l]-=a[r];
				cnt+=a[r];
				a[r]=0;
				r--;
			}
		}
		else{
			if(a[l]<=a[r]){
				a[r]-=a[l];
				cnt+=a[l];
				ans+=a[l];
				a[l]=0;
				l++;
			}
			else{
				a[l]-=a[r];
				cnt+=a[r];
				ans+=a[r];
				a[r]=0;
				r--;
			}			
		}
	}
	cout<<ans;
	
	return 0;
}
