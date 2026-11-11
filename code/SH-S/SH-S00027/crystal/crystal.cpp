#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+7;
long long n,m;
long long a[N],s[N];
long long pos=1,ans=0;
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(long long i=1;i<=n;i++){
		while(pos<i&&(i-pos)*a[i]-(s[i-1]-s[pos-1])>m) pos++;
		ans=max(ans,i-pos+1);
	}
	cout<<ans<<endl;
	
	return 0;
}
