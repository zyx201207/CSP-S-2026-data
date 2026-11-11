#include<bits/stdc++.h>
using namespace std;
long long m,n,a[500010],c=0,ans=0,num=0;
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long x=n/2;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
		for(long long i=x+1;i<=n;i++){
		if(a[i]==a[x]){
			num++;
		}
	}
	for(long long i=x;i>=0;i--){
	if(c<=m){
		c=a[x]-a[i];
		a[i]=a[x];
		num++;
	    }
	}
	cout<<num;
	return 0;
}
