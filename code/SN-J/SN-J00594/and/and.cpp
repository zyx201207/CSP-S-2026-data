#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int minn=1e9;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<minn)minn=a[i];
	}
	cout<<minn;
	return 0;
}
