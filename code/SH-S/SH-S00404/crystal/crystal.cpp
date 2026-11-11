#include<bits/stdc++.h>
#define FILE_NAME "crystal"
using namespace std;
using lld=long long;
const int N=500010;
lld a[N],ans;
int n,m;
int main(){
	freopen(FILE_NAME".in","r",stdin);
	freopen(FILE_NAME".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1,ptr=0,sum=0;i<n;++i){
		sum+=(a[i]-a[i-1])*(i-ptr);
		while(sum>m){
			sum-=a[i]-a[ptr];
			ptr++;
		}
		ans=max(ans,(lld)i-ptr+1);
	}
	cout<<ans;
	return 0;
}
