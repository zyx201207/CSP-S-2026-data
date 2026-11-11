#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500050],sum,cnt,ans;
int main(){
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	sum/=n;
	for(int i=1;i<=n;i++){
		cnt+=abs(a[i]-sum);
		if(cnt>m){
			break;
		}
		ans++;
	}
	cout<<ans;
	return 0;
    
}


