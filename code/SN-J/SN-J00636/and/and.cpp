//wanghaoyu xidianzhongxue SN-J00636
#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxx;
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]>maxx)maxx=a[i];
	}
	cout<<maxx;
	return 0;
}
