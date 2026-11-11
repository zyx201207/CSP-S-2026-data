#include<bits/stdc++.h>
using namespace std;
long long n,a[500011],b[500011],m,ans=1,ans1=0,ma=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	int x=1,z=1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i]!=a[i-1])
			x=0;
		if(a[i]!=i)
			z=0;
		ma+=abs(a[i]);
	}
	if(x==1){
		cout << n;
		return 0;
	}
	if(z==1){
		int i=1;
		ans=1;
		z=0;
		while(z+i<=m){
				z+=i;
				i++;
				ans++;
			}
		cout << ans;
		return 0;
	}
	if(m>ma){
		cout << n;
		return 0;
	}
	sort(a,a+n);
	long long y=a[1],p=1,o=1;
	while(y<=a[n]){
		ans1=0;
		while(a[p]<=y and p<=n)
			p++;
		long long q=m;
		for(int i = p-1;i >= 1 ; i--){
			if(y-a[i]<=q){
				q=q-(y-a[i]);
				ans1++;
			}
			else
				break;
		}
		ans=max(ans,ans1);
		if(ans==n)
			break;
		y++;
	}
	cout << ans;
	return 0;
}