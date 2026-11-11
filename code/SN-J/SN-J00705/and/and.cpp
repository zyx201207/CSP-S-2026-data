//heyuanwei xiantieyizhongxue SN-J00705 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
int n,m;
ll a[maxn];
ll ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			ans=max(ans,a[i]&a[j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
