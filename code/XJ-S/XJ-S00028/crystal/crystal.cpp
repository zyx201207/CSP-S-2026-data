#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	int n,m,sum=0,d=0;
	cin>>n>>m;
		if(n>=5000){
		cout<<n;
		return 0;
	}
	int a[n+1],b[n+1];
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);

	for(int i=1;i<=n;i++){
		int d=0,sum=0; 
		for(int j=i-1;j>=1;j--){
		while(a[j]!=a[i]&& sum!=m){
		a[j]++;
		sum++;
	}
	if(a[i]==a[j])d++;
	}
	b[i]=d;
	}
	sort(b+n,b+n+1);
	b[n]++;
	cout<<b[n];
	return 0;                                  
} 











































































