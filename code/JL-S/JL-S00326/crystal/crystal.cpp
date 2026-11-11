#include<bits/stdc++.h>
using namespace std;
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
int power[50005];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>power[i];
	sort(power+1,power+1+n);
	cout<<power[n/2+1];
	
	return 0;
}
