#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
int n;
ll m,sum,cnt,ans;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum=0,cnt=1;
		for(int j=i-1;j>=1;j--){	
			cnt++;
 	 		if(sum+a[i]-a[j]<=m){
				sum+=a[i]-a[j];
				ans=max(ans,cnt);
			}
			else
				continue;
		}
	}
	cout<<ans;
	return 0;
}