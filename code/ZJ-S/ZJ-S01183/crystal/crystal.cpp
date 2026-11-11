#include<bits/stdc++.h>
using namespace std;
long long a[500005]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1;
	int ans=1;
	long long sum=0;
	for(int i=2;i<=n;i++){
		sum+=(a[i]-a[i-1])*(i-l);
		while(sum>m){
			sum-=a[i]-a[l];
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<'\n';
}