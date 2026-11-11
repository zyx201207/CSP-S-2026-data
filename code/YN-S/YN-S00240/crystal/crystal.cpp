#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXN=5e5+7;
int n,ans=1;
long long m,a[MAXN];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	long long tmp=0;
	for(int i=1,j=2;j<=n;j++){
		tmp+=1ll*(a[j]-a[j-1])*(j-i);
		while(i<=j&&tmp>m) tmp-=a[j]-a[i++];
		ans=max(ans,j-i+1);
	}
	cout<<ans;
	return 0;
}
