#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int T,c;
int n,d;
int a[N],ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			int x=a[i]+d;
			int f=lower_bound(a+i,a+n+1,x)-a;
			//cout<<"*"<<f<<"*"<<endl;
			if(a[f]==x){
				int f2=lower_bound(a+i,a+n+1,x+d)-a;
				if(f2>n)f2=n;
				if(a[f2]<x+d+1)ans+=(f2-f);
				//cout<<"*"<<f<<" "<<f2<<" "<<i<<"*"<<endl;
				else if(x+d>a[n]){
					ans+=(n-f);
				}
			}
			else{
				f--;
				int f2=lower_bound(a+i,a+n+1,a[f]+d)-a;
				if(f2>n)f2=n;
				if(a[f2]==a[f]+d)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	
}
//4 2
//1 2 3 4
//
//5 2
//1 2 3 4 5
//
//5 3
//-2 -1 0 1 2

