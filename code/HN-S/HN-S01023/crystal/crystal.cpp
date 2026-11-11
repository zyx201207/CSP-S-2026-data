#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5; 
int n,m,a[N],ans=0,l=0,sum=0,uo,kl;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		uo=m,kl=1;
		for(int j=i-1;j>=1;j--){
			if(a[j]+uo>=a[i]){
				uo-=(a[i]-a[j]);
				kl++;
			}
			if(uo<=0 || a[i]-a[j]>uo){
				break;
			}
		}
		if(kl>ans){
			ans=kl;
			sum=ans;
			l=i;
		}
	}
	cout<<ans;
	return 0;
}

