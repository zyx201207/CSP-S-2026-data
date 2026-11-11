#include<bits/stdc++.h>
using namespace std;
#define int long long
long long v[1000005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	long long n,m,sum = 0,minx = INT_MAX,ans = 0;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>v[i];
		sum += v[i];
	}sum = sum/n;
	sort(v+1,v+n+1);
	for(int i = 1;i<=n;i++){
		minx = min(minx,abs(v[i]-sum));
	}
	for(int i = 1;i<=n;i++){
		v[i] -= (sum + minx);
	}
	int cnt = 1;
	for(int i = 1;i<=n;i++){
		if(v[i]<=0){
			if(m+v[i]<0){
				break;
			}else{
				m += v[i];
				ans++;
			}
		}else{
			break;
		}
	}
	cout<<ans;
	return 0;
} 
