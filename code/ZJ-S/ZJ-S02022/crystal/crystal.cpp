#include<bits/stdc++.h>
#define int long long
#define N 500010
using namespace std;
int n,m,ans=1;
int a[N],b[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	if(n<=5000){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=n;i>=1;i--){
			int x=m,sum=1;
			for(int j=i-1;j>=1;j--){
				if(x>=a[i]-a[j]){
					x-=(a[i]-a[j]);
					sum++;
				}
			}	
			if(sum>ans){
				ans=sum;
			}
		}
		cout<<ans;
	}
	else{
		int x=a[2]-a[1],ans;
		while(m>0){
			m-=x;
			x+=x;
			ans++;
		}
		cout<<ans;
	}
	return 0;
}
