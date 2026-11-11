#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxx=0,a[200005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		if(a[i]>maxx){
			maxx=a[i];
		}
	}
	cout<<maxx;
	return 0;
}
