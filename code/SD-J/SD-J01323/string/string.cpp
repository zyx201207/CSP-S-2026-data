#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long ans,a[N];
char s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>s[i];
	int l=1,r=n;
	while(l<=r){
		if(s[l]==s[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}else{
				l++,r--;
			}
		}else{
			if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}else if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}else{
				ans+=a[l];
				l++,r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
