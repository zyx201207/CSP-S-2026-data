#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans;
bool f;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=2;i<=n;i++){
		if (m>=(a[i]-a[i-1])*i){
			ans+=1;
			a[i]=a[i-1];
			m-=(a[i]-a[i-1])*i;
		}
		else{
			break;
		}
	}
	cout<<ans+1;
	return 0;
}
