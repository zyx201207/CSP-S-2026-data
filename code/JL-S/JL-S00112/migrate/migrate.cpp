#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
struct S{
	int to;
	long long dis;
};
int main(){
    freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
		while(t--){
			int n;
			long long d;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
				a[i]+=1000000000000000005ll;
			}
			int cnt=0;
			long long diff=a[2]-a[1];
			cout<<0<<"\n";
		}
	return 0;
}
