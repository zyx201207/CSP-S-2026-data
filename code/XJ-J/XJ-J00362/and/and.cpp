#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
bool cmp(int l,int r){
	return l>r;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	if(m==1||a[1]==n-1)cout<<a[1];
	else cout<<a[m];
	return 0;
} 
