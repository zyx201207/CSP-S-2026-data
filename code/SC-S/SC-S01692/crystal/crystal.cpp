#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[500005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n);
	int a1,b;
	for(int i=1;i<=m;i++){
		int ans=0;
		for(int j=1;j<i;j++){
			ans=a[i]-a[j]+ans;
		}
		if(ans>m)break;
		else{
			b=i;
		}
	}
	cout<<b<<endl;
	return 0;
}