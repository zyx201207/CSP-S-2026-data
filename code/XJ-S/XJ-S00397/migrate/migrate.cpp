#include<bits/stdc++.h>
using namespace std;
const int N=2*1e6+10;
int c,t,n,d,a[N],minn=INT_MAX;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		minn=INT_MAX;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i],minn=min(minn,a[i]);
		cout<<minn<<endl;
	}
	return 0;
}
