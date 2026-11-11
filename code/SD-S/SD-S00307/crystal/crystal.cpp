//‘≤√Œ¡À ^-^ 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+5;
int n,m,a[M],b[M],cnt=1,maxx;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++){
		if(m-b[i+1]*i>=0){
			m-=b[i+1]*i;
			cnt++;
		}else{
			cout<<cnt;
			return 0;
		}
	}
	return 0;
} 
