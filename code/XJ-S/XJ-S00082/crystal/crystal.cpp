#include<bits/stdc++.h>
using namespace std;
int a[500020];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long c=a[2]-a[1];
	cout<<(m/c+1);
	return 0;
}
