#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100001];


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long k=1;
	for(int i=n;i>1;i--){
		long long u=m;
		long long y=i-1;
		long long o=1;
		
		while(1){
			if(u>=(a[i]-a[y])&&y>0){
				o++;
				u=u-(a[i]-a[y]);
				y--;
			}
			else{
				if(o>k){
					k=o;
					
				}
				break;
			}
		}
	}
	cout<<k;
	return 0;
}