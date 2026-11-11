#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int a[N];
signed main(){
	int c,t;cin>>c>>t;
	while(t--){
		int n,d;cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			int t1=upper_bound(a+1,a+1+n,a[i]+d)-1-a;
			//cout<<t1<<endl;
			if(t1==i)continue;
			int t2,spos=-1;
			while(1){
				t2=upper_bound(a+1,a+1+n,a[t1]+d)-1-a;
				if(t2==t1)break;
				if(t1<=2){
					t2=t1;
					continue;
				}
				if(a[t2]-a[t1-1]<=d&&a[t2]-a[t1-2]<=d){
					break;
				}
				if(a[t2]-a[t1-1]<=d){
					spos=t2;
					break;
				}
			}
			
		}
	}
	return 0;
}
