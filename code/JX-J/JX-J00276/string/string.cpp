#include <bits/stdc++.h>
using namespace std;
char c[200005];
long long a[200005],n,ans;
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
			if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
				else{
					ans+=a[l];
					a[r]-=a[l];
					l++;
				}
		}else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
				else{
				a[r]-=a[l];
				l++;
			}
		}
		if(a[r]==0)r--;
		if(a[l]==0)l++;
	}	
	cout<<ans;
	return 0;
}
