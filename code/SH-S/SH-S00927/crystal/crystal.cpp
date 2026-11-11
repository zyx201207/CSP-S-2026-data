#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5;
ll n,m,a[N],past=1,now,len=1,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
    	len=i-past+1;
    	now+=(a[i]-a[i-1])*(len-1);
    	while(now>m){
    		len--;
    		now-=a[i]-a[past++];
		}
    	ans=max(ans,len);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
