#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans=0xffffffffff;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}sort(a,a+n,cmp);
	for(int i=0;i<m;i++){
		ans&=a[i];
	}cout<<ans;
	return 0;
}
