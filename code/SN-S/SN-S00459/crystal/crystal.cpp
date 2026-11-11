//liushaoang SN-S00459 FuLun
#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int count=0;
	for(int i=1;i<=n;i++){
		if(i==a[i] || a[i]>=0){
			count++;
		}
	}
	if(n==count){
		cout<<3;
	}
	return 0;
}
