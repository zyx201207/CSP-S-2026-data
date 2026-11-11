#include<bits/stdc++.h>
using namespace std;
long long a[500009];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int cnt=0;
	for(int i=n/2+2;i<=n;i++){
		if(a[i]==a[n/2+1]){
			cnt++;
		}
	}
	cout<<n/2+1+cnt;
}
