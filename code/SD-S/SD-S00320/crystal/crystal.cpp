#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
int n,m,a[500010],l,sum,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	l=1;
	for(int i=1;i<=n;i++){
		sum+=(i-l)*(a[i]-a[i-1]);
//		cout<<"sum += "<<(i-l+1)<<" * "<<(a[i]-a[i-1])<<'\n';
		while(sum>m){
			sum-=a[i]-a[l];
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
} 
