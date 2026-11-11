#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long n,m;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	long long l=1,r=2,ans=2;
	for(long long i=1;i<=n;i++){
		if(m>=l&&m<=r){
			cout<<ans;
			return 0;
		}
		else{
			l=r+1;
			r=l+ans;
			ans++;
		}
	}
	return 0;
}
