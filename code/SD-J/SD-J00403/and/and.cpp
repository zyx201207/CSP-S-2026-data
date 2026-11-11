#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],r;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n,cmp);
	int sum=a[0];
	for(int i=1;i<m;i++)
		sum&=a[i];
	cout<<sum;
	return 0;
}
