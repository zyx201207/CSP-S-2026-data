#include<bits/stdc++.h>
using namespace std;
long long  n,m,a[100000000],p[100000000],d[10000000];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	
	for(int i=n;i>=1;i--){
		for(int j=i-1;j>=1;j--){
			p[i]+=a[i]-a[j];
		}
	}
	
	long long minnn=0;
	for(int i=1;i<=n;i++){
		if(p[i]<=m)
		   minnn=i;
	}
     cout<<minnn;
	return 0;
}
