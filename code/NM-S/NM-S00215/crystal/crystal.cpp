#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m;
long long arr[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	long long ans=0;
	sort(arr+1,arr+n+1);
	for(int i=2;i<=n;i++){
		long long sum=m,a=1;
		for(int j=i;j>=1;j--){
			if(arr[i]<=arr[j-1]+sum){
				a++;
				sum-=(arr[i]-arr[j-1]);
			}else{
				break;
			}
		}
		ans=max(a,ans);
	}
	cout<<ans;
}
