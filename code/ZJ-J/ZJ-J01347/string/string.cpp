#include<bits/stdc++.h>
using namespace std;
long long int hh,tt,n,a[500001],sum;
char c[500001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i]>>c[i];
	}
	hh=1;
	tt=n;
	while(hh<tt){
		if(a[hh]<a[tt]){
			if(c[hh]!=c[tt]){
				sum+=a[hh];
				a[tt]-=a[hh];
				hh++;
			}
			else{
				a[tt]-=a[hh];
				hh++;
			}
		}
		else if(a[hh]==a[tt]){
			if(c[hh]!=c[tt]){
				sum+=a[hh];
			}
			hh++;
			tt--;
		}
		else{
			if(c[hh]!=c[tt]){
				sum+=a[tt];
			}
			a[hh]-=a[tt];
			tt--;
		}
	}
	cout<<sum;
	return 0;
}