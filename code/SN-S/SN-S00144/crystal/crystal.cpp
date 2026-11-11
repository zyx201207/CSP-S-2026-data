#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+10;
ll n,m,a[maxn],maxx; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		ll csp=0,ccf=0;
		for(int j=i;j>=1;j--){
			if(a[i]-a[j]+csp<=m){
				csp+=a[i]-a[j];
				ccf++;
			}else{
				break;
			}
		}
		maxx=max(maxx,ccf);
	}
	cout<<maxx;
	return 0;
}
