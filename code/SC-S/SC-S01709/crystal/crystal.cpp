#include <bits/stdc++.h>
freopen("crystal.in",r,stdin);
freopen("crystal.out",w,stdout);
using namespace std;

int n;
long long m,a[500060];
int mp;

int main(){
	cin>>n>>m;
	if(n<=5000){
	
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
	a[i]=a[i+1]-a[i];
	}
	for(int j=0;j<n-1;j+=1)
	{int sum=0,i=j;
	for(i;sum<=m&&i<n;i++){
	sum+=a[i]*(i-j);
	}
	if(sum<=m){
	mp=max(i-j,mp);
	}
	else mp=max(i-1-j,mp);
	}
	cout<<mp;
}
	else{
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
	a[i]=a[i+1]-a[i];
	}
	int sum=0,i=1;
	for(i;sum<=m&&i<n;i++){
	sum+=a[i]*i;
	}
	if(sum<=m)cout<<i;
	else cout<<i-1;
	
}

	
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}