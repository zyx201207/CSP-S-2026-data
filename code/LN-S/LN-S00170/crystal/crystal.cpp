#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],f[N],k,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
	    k=k+(i-1)*(a[i]-a[i-1]);
	    f[i]=f[i-1]+1;
	    if(k>m){
		    while(k>m){
			    k-=(a[i]-a[i-f[i-1]]);
			    f[i]--;
			}
		}
	}
	for(int i=1;i<=n;i++)ans=max(ans,f[i]);
	cout<<ans;
	return 0;
}
