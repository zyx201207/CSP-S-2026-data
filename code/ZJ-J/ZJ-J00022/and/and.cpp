#include<bits/stdc++.h>
#define N 1000010
#define int long long
using namespace std;
int n,m,i,j,ans,sum,a[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=30;i>=0;i--){
		sum=0;
		for(j=1;j<=n;j++)
			if(((1<<i)&a[j])!=0)sum++;
		if(sum>=m){
			ans+=(1<<i);
			for(j=1;j<=n;j++)
				if(((1<<i)&a[j])==0)a[j]=0;
		}
	}
	cout<<ans;
}
//by wild cat