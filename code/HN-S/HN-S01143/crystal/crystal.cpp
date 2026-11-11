#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int an[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>an[i];
	sort(an+1,an+n+1);
	int ans=0;
	for(int i=2;i<=n;i++){
		int sum=0,cs=m;
		for(int j=i;j>=1;j--){
			if(an[i]-an[j]<=cs){
				sum++;
				cs-=(an[i]-an[j]);
			}else break;
		}
		ans=max(sum,ans);
	}
	cout<<ans;
	return 0;
}


