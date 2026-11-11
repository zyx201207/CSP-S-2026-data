#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=1,num,cnt;
int a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		cnt+=a[i];
	}
	cnt/=n;
	sort(a,a+n);
	num=lower_bound(a,a+n,cnt)-a;
	for(int i=num-1;i>=0;i--){
		if(a[num]-a[i]<=m){
			m-=(a[num]-a[i]);
			ans++;
		}else{
			continue;
		}
	}
	int i=num+1;
	while(a[i]==a[num]){
		ans++;
		i++;
	}
	cout<<ans;
	return 0;
}
