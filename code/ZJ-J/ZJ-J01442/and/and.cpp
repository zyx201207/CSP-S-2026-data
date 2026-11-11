#include<bits/stdc++.h>
using ll=long long;
using namespace std;
ll a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll maxn=0;
	if(m==1){
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
			cout<<maxn;
		}
	}
	else{
		ll i1=0,i2=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if((a[i]&a[j])>maxn&&i!=j){
					maxn=(a[i]&a[j]);
				}
			}
		}
	}
	cout<<maxn;
	
	return 0;
}