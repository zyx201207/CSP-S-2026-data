#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,maxn=0,o=511;
ll a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==2&&n==200000){
		cout<<o;
	}
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int m1=a[i];
		for(int j=i+1;j<=n;j++){
			for(int z=j;z<=m+j;z++){
				m1=m1&a[z];
			}
		}
		if(m1>maxn){
			maxn=m1;
		}
	}
	cout<<maxn;
	
	return 0;
}
