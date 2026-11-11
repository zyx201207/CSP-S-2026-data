#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5*1e5+200;
ll n,m;
ll a[N];
ll cha[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		cha[i]=a[i]-a[i-1];
	}
	int i=1;
	while(m>=(cha[i]*(i-1))){
		m-=(cha[i]*(i-1));
		i++;
	}
	cout<<i-1<<endl;
	return 0;
}

