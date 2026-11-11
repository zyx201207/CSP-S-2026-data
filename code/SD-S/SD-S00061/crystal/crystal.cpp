#include<bits/stdc++.h>
using namespace std;
long long n,a[50000005],b[50000005];
long long m;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		
		b[i]=abs(a[i]-a[i-1]);
	}
	int cnt=0;
	int j=1;
	while(m>=0){
		m-=j*b[j+1];
		j++;
		cnt++;
		
		
	}
	cout<<cnt;
	return 0;
} 
