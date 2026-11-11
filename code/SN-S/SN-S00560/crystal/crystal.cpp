#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int t=a[2]-a[1];
	int sum=0;
	for(int i=1;i<=n;i++){
		if((sum*t)>m){
			cout<<i-1;
			return 0;
		}
		else{
			sum+=i;
		}
	}
	cout<<n;
	return 0;
}
