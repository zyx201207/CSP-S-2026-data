#include<bits/stdc++.h>
using namespace std;
int n,a[100010],m;
long long sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		a[i]-=a[i-1];
	}
	for(int i=2;m>0;++i){
		m-=a[i];
		sum++;
	}
	cout<<sum;
	return 0;
}