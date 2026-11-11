#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<utility>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#define int long long
using namespace std;
int a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,now=0,l=1,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int i;
	for(i=2;i<=n;i++){
		while(((a[i]-a[i-1])*(i-l)+now>m)&&(l<i)){
			now-=a[i-1]-a[l++];
		}
		now+=(a[i]-a[i-1])*(i-l);
		ans=max(ans,i-l+1);
		cout<<ans<<l<<i<<now<<' ';
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

