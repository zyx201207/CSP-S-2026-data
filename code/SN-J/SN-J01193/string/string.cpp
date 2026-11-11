#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+7;
ll n,a[N],sum=0;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	ll mid=n/2;
	ll cnt=1;
	while(mid--){
		if(c[cnt]!=c[n]){
			sum+=max(a[cnt],a[n]);
		}
		cnt++;n--;
	}
	cout<<sum;
	return 0;
}
