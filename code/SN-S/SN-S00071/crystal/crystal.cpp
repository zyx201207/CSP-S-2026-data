#include <bits/stdc++.h>
using namespace std;
long long n,m,a[505000],l=1,r=1,shunum=1,zhinum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<=1){
		cout<<"1";
		return 0;
	}
	zhinum=0;
	while(r<n){
		r++;
		zhinum+=(r-l)*(a[r]-a[r-1]);
		if(zhinum>m){
			while(zhinum>m){
				zhinum-=a[r]-a[l];
				l++;
			}
		}
		if((r-l+1)>shunum){
			shunum=r-l+1;
		}
	}
	cout<<shunum;
	return 0;
}
