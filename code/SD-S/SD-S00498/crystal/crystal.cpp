#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
long long n,a[N],l,ans,m,sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	l=1;
	for(int i=1;i<=n;i++){
		sum=sum+a[i];
		while((i>=l)&&sum+m<a[i]*(i-l+1)){sum-=a[l];l++;} 
		ans=max(ans,i-l+1);
	}cout<<ans;
	return 0;
}
