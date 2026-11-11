//zhanzghitong xianshidibashijiuzhongxue SN-J00628
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int maxx=-1;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
	}
	
	
	return 0;
}

