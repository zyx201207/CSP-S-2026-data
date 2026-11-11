#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N],n,ans;
string s[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >>a[i] >> s[i];
	}
	int l=1,r=n;
	int f=0;
	while(l<r){
		if(s[l]==s[r]){
			if(a[l]==a[r]){
				l++;r--;
				continue;
			}
			if(a[l]!=a[r]){
				if(a[l]>a[r]){
					a[l]-=a[r];
					r--;
					continue;
				}if(a[l]<a[r]){
					a[r]-=a[l];
					l++;
					continue;
				}
			}
		}
		if(s[l]!=s[r]){
			if(a[l]==a[r]){
				ans+=a[l];
				l++;r--;
				continue;
			}else{
				if(a[l]>a[r]){
					a[l]-=a[r];
					ans+=a[r];
					r--;
					continue;
				}if(a[l]<a[r]){
					a[r]-=a[l];
					ans+=a[l];
					l++;
					continue;
				}
			}
		}
	}
	cout << ans;
	return 0;
}