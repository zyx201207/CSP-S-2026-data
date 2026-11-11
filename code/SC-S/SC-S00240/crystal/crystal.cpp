#include<bits/stdc++.h>
using namespace std;
long long m,n;
long long cnt;
long long  lar=0;
int a[50005];
int b[50005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	b[1]=0;
	for(int i=2;i<=n;i++)b[i]=a[i]-a[i-1];
	for(int i=1;i<=n;i++){
		int cnt=0;
		long long ans=0;
		while(m>=cnt&&(i+ans)<=n){
			cnt+=ans*b[i+ans];
			ans++;
		}
		if(ans>lar)lar=ans; 
	}
	cout<<lar-1;
	return 0;
} 