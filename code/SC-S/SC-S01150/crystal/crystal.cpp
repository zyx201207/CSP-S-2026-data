#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long cha[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		cha[i]=a[i+1]-a[i];
	}
	long long now=0;
	for(int i=1;i<=n;i++){
		now+=((i-1)*cha[i-1]);
		if(now>m){
			cout<<i-1;
			return 0;
		}
	}
	cout<<n;
	return 0;
}