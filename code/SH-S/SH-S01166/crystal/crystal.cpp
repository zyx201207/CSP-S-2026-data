#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a[500000];
	cin >> n >> m;
	for (int i=0;i<n;i++) {
		cin >> a[i];
	}
	sort(a,a+n);
	int minus[500000];
	int platform=0;
	for (int i=1;i<n;i++) {
		if (a[i]>a[i-1]) minus[i]=i*(a[i]-a[i-1])+minus[i-1];
		else{
			 minus[i]=minus[i-1];
		}
		if (minus[i]>m){
		   if (minus[i-1]<=m){
		   	  platform=i;
		   }
		   break;
		}	
	}
	for (int i=platform+1;i<n;i++){
		if (a[i]==a[platform]) platform++;
	}
	if (platform==0) platform=n;
	cout << platform;
	
}
