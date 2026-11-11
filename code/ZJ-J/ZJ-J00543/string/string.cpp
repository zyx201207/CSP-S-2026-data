#include<bits/stdc++.h>
using namespace std;
const int ac=2e5+10;
long long ans=0;
long long a[ac];
int l=1,r;
string s[ac];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	while(l<=r){
		if(s[l]==s[r]){
			if(a[l]<a[r]){
				l++;
			}else if(a[l]>a[r]){
				r--;
			}else{
				l++;
				r--;
			}
		}else{
			if(a[l]<a[r]){
                ans+=a[l];
				a[r]=a[r]-a[l];
				l++;
			}else if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}else{
				ans+=a[l];
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}