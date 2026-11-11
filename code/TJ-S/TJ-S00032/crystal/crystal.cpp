#include<bits/stdc++.h>
using  namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	vector <long long> a(n+1);
	vector <long long> b(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=llabs(a[i]-a[i-1]);
	}
	sort(b.begin(),b.end());
	int ans=0;
	for(int i=1;i<=n;i++){
		m-=b[i];
		if(m>=0)ans++;
	}
	cout<<ans;
	return 0;
} 
