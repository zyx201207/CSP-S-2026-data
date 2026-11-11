#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N];
int n,m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=5000&&m<=1e9||m<=1e8){	
		int maxn=0;
		for(int i=1;i<=n;i++){
			if(a[i]==a[i+1]){
				continue;
			}
			int sum=0,cnt=1;
			for(int j=i-1;j>=1;j--){
				sum+=a[i]-a[j];
				if(sum>m){
					break;
				}else{
					cnt++;
				}
			}
			maxn=max(maxn,cnt);
		}
		cout<<maxn<<"\n";
	}else{
		int k=a[2]-a[1];
		cout<<floor(sqrt(k*k+8*k*m)/(2.0*k)+0.5)<<"\n";
	}
	return 0;
}