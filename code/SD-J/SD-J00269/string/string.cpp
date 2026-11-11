#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=2e5+10;
ll a[N];
char b[N];
ll n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a[i]>>b[i];
	}
  	int l=0,r=n-1;
  	while(l<r){
  		if(b[l]!=b[r]){
  			ans+=min(a[l],a[r]);	
		}
		if(a[l]<a[r]){
			a[r]-=a[l];l+=1;
			continue;
		}
		if(a[r]<a[l]){
			a[l]-=a[r];r-=1;
			continue;
		}
		if(a[r]==a[l]){
			l+=1,r-=1;
			continue;
		}
		
	}
	cout<<ans;
	return 0;
}

