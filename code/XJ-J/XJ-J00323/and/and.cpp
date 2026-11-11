#include<bits/stdc++.h> 
using namespace std;
#define int long long 
const int N=2e5+5;
int a[N],n,m,ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	reverse(a+1,a+1+n);
	for(int i=1;i<=n-m+1;i++){
		int cnt=a[i];
		for(int j=i+1;j<=i+m-1;j++){
			cnt&=a[j];
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
 /*
1000
0111
0100
0011
0011



     1
    11
   111
  1111
 11111
1
*/
