#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000005],d[1000005],s[1000005],sum; 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int t=0,f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			f=1;
		}
	}
	s[1]=0;
	for(int i=2;i<=n;i++){
		s[i]=a[i]-a[i-1];
		if(s[i]!=s[2]){
			t=1;
		}
	}
	if(f==0||t==0){
		cout<<min(n,m/2+1);
		return 0;
	}
	for(int i=1;i<=n;i++){
		int ans=0;
		for(int j=1;j<=n;j++){
			d[j]=abs(a[i]-a[j]);
		}
		sort(d+1,d+1+n);
		int x=m;
		for(int i=1;i<=n;i++){
			if(x>=d[i]){
				x-=d[i];
				ans++;
			}else{
				break;
			}
		}
		sum=max(ans,sum);
	}
	cout<<sum;
	return 0;
}

