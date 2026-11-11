#include <bits/stdc++.h>
using namespace std;
long long n=0,m=0,a[5000005]={0};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long j=0;j<n;j++){
		cin>>a[j+1];
	}
	sort(a+1,a+1+n);
	long long i=1;
	while(m>0){
		if(a[i]==a[i+1]){
			i++;
			continue;
		}
		m-=i;
		cout<<m<<endl; 
		a[i]++;
	}
	if(a[i-1]==a[i]) i++;
	cout<<i;
	return 0;
}
