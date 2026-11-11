#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const long long N=5e5+7;
long long n,m;
long long a[N];//原值 
long long w[N];//大小 
long long idx;//指向 
long long ans;//答案 
long long cnt;//个数 
long long zhi[N];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(long long i=1;i<=n;i++){
		if(a[i]!=a[i-1]){
			w[++cnt]=a[i];
			zhi[cnt]=i;
		}
	}
	for(long long i=1;i<=cnt;i++){
		long long u=zhi[i];
		idx=max(idx,u);
		m+=(idx-zhi[i])*(w[i-1]-w[i]);
		while(m>=(a[u]-a[idx])&&idx<=n){
			m-=(a[u]-a[idx]);
			idx+=1;
		}
		ans=max(ans,idx-u);
	}
	cout<<ans;
}
