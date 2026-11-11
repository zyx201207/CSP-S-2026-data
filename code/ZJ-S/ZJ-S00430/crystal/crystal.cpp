#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,a[N],maxx=1,sub,sum;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int s=0,j=1;
	for(int i=1;i<=n;i++){
		
		sum+=(i-j)*(a[i]-s);
		s=a[i];
		if(sum>m){
			while(sum>m){
				sum-=(s-a[j]);
				j++;
			}
		}
		maxx=max(i-j+1,maxx);
	}
	cout<<maxx;
	return 0;
}
