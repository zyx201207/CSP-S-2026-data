#include <bits/stdc++.h>
using namespace std;
long long a[500005];
int n;
long long m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long x=a[2]-a[1];
	long long sum=1;
	for(int i=2;i<=n;i++){
		long long y=(i-1)*x;
		if(m>=y){
			m-=y;
			sum++;
		}
	}
	cout<<sum;
    return 0;
}
