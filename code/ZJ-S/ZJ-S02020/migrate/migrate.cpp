#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[2000050],ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
//		lbegin=1;
//		lend=1;
//		last=a[1];
//		for(int i=2;i<=n;i++){
//			cnt=0;
//			last=a[i];
//			//lbegin
//			//lend=i;
//			while(++cnt){
//				int x=upper_bound(a+1,a+1+n,last+d)-a-1;
//				for(int j=lasti+1;j<=x;j++){
//					int y=lower_bound(a+1,a+1+n,a[j]-d)-a;
//					if(lend-y+1==2){
//						ans++;
//					}
//				}
//			}
//		}
		ans=0;
		for(int i=1;i<=n;i++){
			int lbegin=i,lend=i,last=a[i];
			while(1){//cout<<i<<' '<<lbegin<<' '<<lend<<' '<<last<<endl;
				int x=upper_bound(a+1,a+1+n,last+d)-a-1;
				if(x==lend){
					break;
				}
				for(int j=lend+1;j<=x;j++){
					int y=lower_bound(a+1,a+1+n,a[j]-d)-a;
					y=max(y,lbegin);//cout<<x<<' '<<lend<<' '<<y<<endl;
					if(lend-y==1)
						ans++;
				}
				lbegin=lend+1;
				lend=x;
				last=a[x];
			}	
		}
		cout<<ans<<endl;
	}
}
