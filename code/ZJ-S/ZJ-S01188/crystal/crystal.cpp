#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e5+10;
int a[N];
int sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	int anss=LLONG_MIN,ans=0;
	for(int i=1,j=1;i<=n;i++){
		ans+=((a[i]-a[i-1])*(i-j));
		while(1){
			if(ans<=m)break;
			ans-=(a[i]-a[j]);
			j++;
		}
		anss=max(anss,i-j+1);
	}
	cout<<anss;
	return 0;
}
/*
code by Ace
*/
