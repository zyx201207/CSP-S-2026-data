#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		int ma=0;
		for(int i=1;i<=n;i++)
			ma=max(ma,a[i]);
		cout<<ma;
	}else if(n==m){
		int ma=a[1];
		for(int i=2;i<=n;i++)
			ma&=a[i];
			cout<<ma;
	}else if(2==m){
		int ma=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ma=max(ma,a[i]&a[j]);
		cout<<ma;
	}else{
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}
	return 0;
}
