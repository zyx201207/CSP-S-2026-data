#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
    cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
sort(a+1,a+n+1);
	int v=n-m+1;
	if(a[n]==n-1&&m%2!=0){
		v-=1;
	}
	cout<<a[v];
	return 0;
}
