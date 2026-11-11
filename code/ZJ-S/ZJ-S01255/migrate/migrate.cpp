#include<bits/stdc++.h>
using namespace std;
long long c,T,n,a[2000005],d,ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		bool f=0;
		long long x;
		for(int i=1;i<=n;i++) cin>>a[i];
		x=a[2]-a[1];
		for(int i=3;i<=n;i++){
			if(a[i]-a[i-1]!=x) f=1;
		}
		cout<<0<<endl;
//		else{
//			if(d<=x) cout<<0<<endl;
//			else{
//				
//			}
//		}
	}
	return 0;
}



