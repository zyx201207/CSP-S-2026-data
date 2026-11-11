#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500001],ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int least=1,cnt=0;
	for(int i=2;i<=n;i++){
		cnt+=(a[i]-a[i-1])*(i-least);
		while(cnt>m){
			cnt-=a[i]-a[least];
			least++;
		}
		ans=max(ans,i-least+1);
	}
	cout<<ans;
	return 0;
}
