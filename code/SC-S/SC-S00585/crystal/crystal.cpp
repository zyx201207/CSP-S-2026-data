#include<bits/stdc++.h>
using namespace std;
const int N=500010;
long long n,m;
long long a[N];
long long mx,maxx;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		long long sum=m;
		mx=1;
		for(int j=i-1;j>=1;j--){
			if(a[i]-a[j]>sum){
				continue;
			}else{
				mx++;
				sum-=a[i]-a[j];
			}
		}
		maxx=max(maxx,mx);
	}
	cout<<maxx;
	return 0;
}