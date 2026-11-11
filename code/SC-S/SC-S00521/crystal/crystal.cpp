#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int j=1;
	//cout<<"i "<<"m "<<"a[i] "<<"a[i+1]-a[i] "<<"j "<<"s\n";
	for(int i=1;i<=n;i++){
		//cout<<i<<' '<<m<<' '<<a[i]<<' '<<a[i+1]-a[i]<<' '<<j<<' '<<'\n';
		if(m<=0)break;
		if(m-j*(a[i+1]-a[i])>=0){
			m=m-j*(a[i+1]-a[i]);
			j++;
			for(int k=1;k<=j;k++)
			a[k]+=(a[i+1]-a[i]); 
		}	
	}
	int l=1;
	while(a[l]==a[l+1]){
		l++;
	}
	cout<<l;
	return 0;
} 