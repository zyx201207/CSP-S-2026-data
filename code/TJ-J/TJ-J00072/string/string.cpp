#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],l,r,ans;
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n-1;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}while(l<r){
		if(c[l]==c[r]){
			if(a[l]==a[r]){
				l++;
				r--;
			}
			else if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else{
				a[r]-=a[l];
				l++;
			}
		}
		else{
			if(a[l]==a[r]){
				ans+=a[l];
				l++;
				r--;
			}
			else if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}else{
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
		}
	}cout<<ans;
	return 0;
}
