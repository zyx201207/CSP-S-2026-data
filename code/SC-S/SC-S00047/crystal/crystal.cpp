#include<bits/stdc++.h>
using namespace std;
bool flag=true;
int n;
long long m;
long long a[500005];
__int128 sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=3;i<=n;i++) if(a[i]-a[i-1]!=a[i-1]-a[i-2]) flag=false;
	if(flag){
		for(int i=1;i<=n;i++){
			__int128 now=a[i];
			now*=(i-1);
			now-=sum[i-1];
			if(now>m){
				cout<<i-1;
				return 0;
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			bool flag=true;
			for(int j=i;j<=n;j++){
				__int128 now=a[j];
			    now*=(i-1);
			    now-=(sum[j-1]-sum[j-i]);
			    if(now<m){
			    	flag=false;
			    	break;
				}
			}
			if(flag){
				cout<<i-1;
				return 0;
			}
		}
	}
	return 0;
}