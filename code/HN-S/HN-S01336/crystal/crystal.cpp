#include<bits/stdc++.h>
using namespace std;
long long a[1000009];
int n,m;
long long dp[1000005]; 
int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=0;
	int i=1;
	while(m>0){
		b=a[i+1]-a[i];
		m-=b;
		for(int j=1;j<=i;j++){
			a[i]+=b/i;
		}
		i++;
	}
	for(int i=0;i<n;i++){
		if(a[i]==a[i+1])cnt++;
	}
	cout<<cnt;
	return 0;
}
