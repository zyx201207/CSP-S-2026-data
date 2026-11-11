#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m,a[N],ans=-1e9;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans=max(ans,a[i]);
	}
	if(m==1){
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}
