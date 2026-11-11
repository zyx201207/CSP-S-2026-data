#include <bits/stdc++.h>
using namespace std;
long long n,m;
int a[100005];
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	int k;
	for(int i=2;i<=n;++i){
		if(a[i]<a[i-1]){
			k=a[i];
			a[i]=a[i-1];
			a[i-1]=k;
		}
	}
	int la=ceil(n/2)+1;
	for(int i=la;i>=0;--i){
		while(m>0&&a[i]<a[la]){
			a[i]++;
			m--;
		}
	}
	for(int i=1;i<=n;++i){
		if(a[i]==a[la]){
			ans++;
		} 
	}
	cout<<ans<<endl;
	return 0;
} 
