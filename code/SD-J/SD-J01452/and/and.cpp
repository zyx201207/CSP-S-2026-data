#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10;
LL a[N],n,m,ans=0,sum;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>m;i--){
		sum=a[i];
		//cout<<sum<<endl;
		if(sum<ans) break;
		for(int j=i;j>i-m;j--){
			sum=sum&a[j];
            if(sum<ans) break;
		}
		ans=max(ans,sum);
		if(ans>=a[i-1]) break;
	}
	cout<<ans;
	return 0;
}
