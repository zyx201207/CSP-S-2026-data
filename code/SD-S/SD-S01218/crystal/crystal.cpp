#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int cha=a[2]-a[1];
	int i=1;
	while(m>=i*cha){
		m-=i;
		i++;
	}
	cout<<i;
	return 0;
}
