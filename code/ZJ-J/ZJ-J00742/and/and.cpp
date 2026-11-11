#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,a[200010],ans;
bool cmp(int q,int h){
	return q>h;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	ans=a[1];
	for(i=2;i<=m;i++){
		if(ans&a[i]==0){m++,i++;continue;}
		ans&=a[i];
	}
	cout<<ans;
}
