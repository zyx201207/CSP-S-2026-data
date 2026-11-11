#include<bits/stdc++.h>
using namespace std;
int a[500005]={};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,zb;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
	    long long minn=1e12+5;
	    for(int j=1;j<=n;j++){
	    	if(abs(a[j+1]-a[j])<=minn and abs(a[j+1]-a[j])!=0){
	    		minn=abs(a[j+1]-a[j]);
	    		zb=j;
			} 
		}if(a[zb+1]>a[zb]) a[zb]++;
		else a[zb+1]++;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]==a[zb]) cnt++;
	}
	cout<<cnt;
	return 0;
} 
