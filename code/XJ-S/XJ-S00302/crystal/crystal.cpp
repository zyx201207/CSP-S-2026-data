#include<bits/stdc++.h>

using namespace std;
long long n,m,t=1,cnt;
int a[500010],num[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.ont","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<n;i++){
		num[i-1]=a[i]-a[i-1];
	}
	while(m>=1){
		m-=num[t]*t;
		t++;
	}
	if(m<0)t--;
	for(int i=t+1;i<=n;i++){
		if(a[i]==a[t])cnt++;
		else break;
	}
	cout<<t+cnt;
	return 0;
} 
