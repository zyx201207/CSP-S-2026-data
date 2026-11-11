#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],b[200005],maxn=INT_MIN;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	int ans=a[0];
	for(int i=0;i<m;i++){
		ans=a[i]&ans;
	}
	cout<<ans;
	return 0;
}
