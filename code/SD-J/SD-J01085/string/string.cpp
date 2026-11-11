#include<bits/stdc++.h>
using namespace std;
int n,l,r;
long long a[200005],ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	l=1;
	r=n;
	while(l<r){
		if(a[l]==a[r]){
			if(c[l]==c[r]){
				l++;
				r--;
			}else{
				ans+=a[l]*1ll;
				l++;
				r--;
			}
		}else if(a[l]>a[r]){
			if(c[l]==c[r]){
				a[l]-=a[r];
				r--;
			}else{
				ans+=a[r]*1ll;
				a[l]-=a[r];
				r--;
			}
		}else{
			if(c[l]==c[r]){
				a[r]-=a[l];
				l++;
			}else{
				ans+=a[l]*1ll;
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}

