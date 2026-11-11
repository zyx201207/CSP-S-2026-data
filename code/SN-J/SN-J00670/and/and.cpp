//maqinxin kunluzhongxue SN-J00670
#include<istream>
#include<bits/stdc++.h>

using namespace std;
int main(){
	int n,m,a[1000],ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	cin>>a[i];
	}
	for(int i=0;i<=n;i++){
	    for(int i=0;i<=m;i++){
	    ans=ans+a[i];
	}
	}
	cout<<ans;
	return 0;}
