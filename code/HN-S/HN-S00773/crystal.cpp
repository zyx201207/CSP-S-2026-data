#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500001],ccf[500001],ans,c[500001];
bool flag=0;
/*
                  _______
                  |RP++!|
                     |
_____________________V_______________
 01000010001000011101101100101010101
-------------------------------------

luogu user:1476867



1 2 4 8 9
4 6 8 8 0
4 10 18 26 26
18
*/
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ccf[i]=a[i]-a[i-1];
		
	}
	for(int i=2;i<=n;i++){
		if(ccf[i]!=ccf[i-1]){
			flag=1;
		}
	}
	if(!flag){
		long long bzd=0;
		for(int i=1;i<=n;i++){
			
			if(bzd>m){
				cout<<i-1;
				return 0;
			}
			bzd+=ccf[2]*i;
		}
	}
	for(int i=1;i<=n;i++){
		long long hello=1,f=m,bdn=0;
		for(int j=i-1;j>=1;j--){
			if(f>=a[i]-a[j]){
				hello++;
				f-=a[i]-a[j];
			}
		}
		ans=max(ans,hello);
	}
	cout<<ans;
	return 0;
}

