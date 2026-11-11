#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+9;
int n,m,a[N],maxx=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1,j=1;i<=n&&j<=n;i++){
		if(i==n){
			cout<<max(maxx,n-j+1);
			return 0;
		}
		if(m<(a[i+1]-a[i])*(i-j+1)){
			maxx=max(maxx,i-j+1);
			m+=(a[i]-a[j]);j++;i--;
		}
		else m-=(a[i+1]-a[i])*(i-j+1);
	}cout<<-1;
	return 0;
}
