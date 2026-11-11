#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d;
int cnt[5005][5005];
long long a[2000005];	
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
//		if(d<=(a[2]-a[1])) 
//		n-2*d/(a[2]-a[1])-1
//		cout<<n<<" "<<d<<" "<<a[2]-a[1]<<"\n";
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++){
//				int now=i,cnt=0;
//				while(now<j){
//					auto it=upper_bound(a+now,a+j+1,a[now]+d);
//					it--;
//					if(it==a+now) break;
//					now=it-a,cnt++;
//				}
//			}
//		}
		cout<<n-2*d/(a[2]-a[1])-1<<"\n";
	}
	return 0;
}
