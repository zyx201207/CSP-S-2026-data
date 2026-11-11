#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long sum[200005];
long long maxx=-2147483647;
int flag=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) sum[1]==a[1];
		else{
			sum[i]=sum[i-1]&a[i];
		}
		if(a[i]%2==0) flag=0;
	}
	

	if(m=n-1){
		for(int i=1;i<=n;i++){
			maxx=max(maxx,sum[i]|a[i]);
		}
		cout<<maxx;
	}
	else if(flag==0){
		cout<<a[n];
	}
	else cout<<a[n-m+1];
	return 0;
}
