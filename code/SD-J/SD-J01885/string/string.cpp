#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int n,a[N],sum;
char c[N];
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	int ans=0;
	int l=1,r=n;
	while(l<=r){
		if(a[l]>a[r]){
			if(c[l]!=c[r]){
				ans+=a[r];
			}
			a[l]-=a[r];
			r--;
		}
		else if(a[l]<a[r]){
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			a[r]-=a[l];
			l++;
		}
		else
		{
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			l++,r--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
