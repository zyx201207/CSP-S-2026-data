#include<bits/stdc++.h>
using namespace std;
long long n,m,sum=0;
long long a[55555],b[55555];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			int rt=a[i]-a[j];
			b[i]+=rt;
		}
	}
	for(int i=1;i<=n;i++){
		if(b[i]>m){
			cout<<i-1;
			return 0;
		}
	}
	return 0;
}
