#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],m,sum=-1,mx=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			sum=a[i]&a[j];
			if(mx<sum)mx=sum;
		}
	}
	cout<<mx;
	return 0;
} 
