#include<bits/stdc++.h>
#define ll long long
using namespace std;
unsigned ll m;
ll n,a[500005],k,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++){
		k=i;
		unsigned ll temp=m;
		ll nowV=a[i];
		while(m>=0 && k!=n){
			if(m<(k-i+1)*(a[k+1]-nowV)) break;
			m-=(k-i+1)*(a[k+1]-nowV);nowV=a[k+1];
			nowV=a[++k];
		}
		m=temp;
		ans=max(ans,k-i+1);
		if(k+1==n) break;
	}
	cout<<ans;
	return 0;
}

