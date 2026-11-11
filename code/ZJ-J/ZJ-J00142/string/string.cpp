#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	ll ans=0;
	while(l<=r){
		if(a[l]>a[r]&&c[l]!=c[r]){
			ans+=a[r];
			a[l]-=a[r];
			r--;
		}
		else if(a[l]<a[r]&&c[l]!=c[r]){
			ans+=a[l];
			a[r]-=a[l];
			l++;
		}
		else if(a[l]==a[r]&&c[l]!=c[r]){
			ans+=a[l];
			l++;
			r--;
		}
		else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}
			else{
				l++;
				r--;
			}
		}
	}
	cout<<ans;
return 0;
}