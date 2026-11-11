#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,m;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	cout<<a[m];
	return 0;
}
