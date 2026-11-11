#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,t=0,a[N],i=1,j=1,ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	while(i<n){
		while(i<n){
			i++;
			t+=(i-j)*(a[i]-a[i-1]);
			if(t>m)break;
			ans=max(ans,i-j+1);
		}
		while(t>m){
			t-=a[i]-a[j];
			j++;
		}
	}
	cout<<ans;
	return 0;
}
