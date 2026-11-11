#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100000010];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int t=a[2]-a[1];
	int sum=0,i=1;
	while(sum<=m){
		t*=i;
		sum+=t;
		i++;
	}
	cout<<i-1;
	return 0;
}
