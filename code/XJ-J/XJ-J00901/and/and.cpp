#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],max1=INT_MIN;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.ans","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		max(a[i],max1);
	}
	cout<<max1;
	return 0;
}