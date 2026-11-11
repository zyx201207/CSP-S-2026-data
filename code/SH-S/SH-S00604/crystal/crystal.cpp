#include<bits/stdc++.h>
using namespace std;
long long a[500005],s[500005],n,m,k,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	k=1;
 	for(int i=1;i<=n;i++){
		if(a[i]*(i-k)-(s[i-1]-s[k-1])<=m) ans=max(ans,i-k+1);
		else{
			while(k<i){
				k++;
				if(a[i]*(i-k)-(s[i]-s[k-1])<=m){
					ans=max(ans,i-k+1);
					break;
				}
			}
		}
	} 
	cout<<ans<<"\n";
	return 0;
}
