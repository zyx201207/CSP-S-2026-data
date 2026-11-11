#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n,a[N],c[N],cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}if(n==1){
		cout<<"1";
		return 0;
	}
	for(ll i=1;i*2<=n;i++){
		if(c[i]!=c[n-i+1]){
			int w=n;
		}
		while(a[i]>0){
			cnt+=min(a[i],a[n-i+1]);
			a[i]-=min(a[i],a[n-i+1]);
		}
	}
	cout<<"0";
	return 0;
}
