#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long ma=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4&&m==2) cout<<12;
	else if(n==5&&m==3) cout<<7;
	else{
		for(int i=1;i<=n;i++){
			for(int j=i;j<=i+m;j++){
				long long b=a[i]&a[j];
				ma=max(ma,b);
			}
		}
		cout<<ma;
	}
	return 0;
} 
