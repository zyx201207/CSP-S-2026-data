#include<bits/stdc++.h>
using namespace std;
long long n,m,lastpay,last_cnt,maxx;
long long a[500005];
long long cha[500005];
long long ans[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	lastpay=0;
	last_cnt=1;
	for(int i=2;i<=n;i++){
		if(m-lastpay>=last_cnt*(a[i]-a[i-1])){
			ans[i]=last_cnt+1;
			lastpay+=last_cnt*(a[i]-a[i-1]);
			last_cnt++;
		}
		else{
			while(1){
				lastpay-=(a[i-1]-a[i-last_cnt]);
				last_cnt--;
				if(m-lastpay>=last_cnt*(a[i]-a[i-1])){
					ans[i]=last_cnt+1;
					lastpay+=last_cnt*(a[i]-a[i-1]);
					last_cnt++;
					break;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		maxx=max(maxx,ans[i]);
	}
	cout<<maxx;
	return 0;
}
