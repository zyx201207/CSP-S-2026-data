#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	long long s=0;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,x,q=0;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=2;i<=n;i++){
		for(long long j=1;j<=i;j++){
			if(s>=m){
				x=a[j];
				break;
			}
			s+=(a[i]-a[j]);
			a[j]=a[i];
		}
	}
	for(long long i=1;i<=n;i++){
		if(a[i]==x)q++;
	}
	cout<<q;
	return 0;
}