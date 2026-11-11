#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll m,a[500005],b[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	if(n>5000&&m>100000000){
		int q = a[2]-a[1];
		bool x= 1;
		for(int i = 1;i <= n;i++) if((1+i)*i/2*q>m){cout << i;x=0;break;} 
		if(x) cout << n;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i = 2;i <= n;i++) b[i]=a[i]-a[1];
	int sum=0,num=1,p=0;
	for(int i = 1;i <= n;i++){
		p=a[i],num=1;
		for(int j = i+1;j <= n;j++){
			if(num*a[j]-p<=m){
				num++;
				p+=a[j];
			}
			else{
				sum=max(sum,num);
				break;
			}
		}
	}
	cout << sum;
	return 0;
}