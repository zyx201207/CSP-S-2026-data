#include <bits/stdc++.h>
using namespace std;
long m;
int a[500100],n,ma=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>1;i--){
		int ans=0;
		int c=m;
		for(int j=i;j>0;j--){
			if(c-a[i]+a[j-1]>=0){
				ans++;
				c=c-a[i]+a[j-1];
			}else{break;}
		}
		if(ans>=ma){
			ma=ans;
		}
	}
	cout<<ma+1;
	return 0;
}
	
