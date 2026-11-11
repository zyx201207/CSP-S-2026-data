#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,t,a[N],n,d,b[N],cnt;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int ans=0;
		cnt=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int now=1;
		for(int i=1;i<=n;i++){
			while(a[now]<=a[i]+d&&now<=n){
				now++;
			}
			b[i]=now-1;
	//		cout<<b[i]<<" ";
		}
	//	cout<<"\n";
		for(int i=1;i<=n;i++){
			if(b[i]-i==2){
			//	cout<<i<<" ";
				now=i+1;
				int k=0;
				ans=0;
				while(now+1<=n){
					if(b[now+1]>b[now]){
						if(!k) ans+=b[now]-now-1;
						break;
					}
					if(b[now]-now>=3){
						ans+=b[now]-now-1;
						if(b[now-3]<b[now]&&b[now-2]>=b[now]) now=b[now]-2;
						else break;
						k=0;
					}else if(b[now]-now==2){
						ans+=1;
						now+=3;
						k=1;
					}else{
						break;
					}
				}
				for(int j=i;j>0;j--){
					if(b[j]-j==1){
						cnt+=ans;
				//		cout<<j<<"   ";
					}
				}
				cnt+=ans;
			//	cout<<ans<<"\n";
			}
		}
		cout<<cnt<<"\n";
	}
}