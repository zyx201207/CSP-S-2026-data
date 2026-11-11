#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans=1,lmoney,lsum;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int fl1=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>2){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2])fl1=0;
		} 
	}sort(a+1,a+n+1);
	if(fl1){
		int x=m,sum=1;
		for(int i=n-1;i>=1;i--){
			if(a[n]-a[i]<=x){
				x-=(a[n]-a[i]);
				sum++;
			}else{
				break;
			}
		}cout<<sum;
		return 0;
	}int l=1;
	if(a[2]-a[1]<=m){
		lmoney=m-(a[2]-a[1]);
		lsum=2;
	}else{
		l=2;
		lmoney=m;
		lsum=1;
	}
	for(int i=3;i<=n;i++){
		lmoney-=lsum*(a[i]-a[i-1]);
		
		while(lmoney<0){
			l++;
			lsum--;
			lmoney+=(a[i]-a[l]);
		}
		lsum++;
		ans=max(ans,lsum);
	}cout<<ans;
	return 0;
}