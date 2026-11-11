#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000010],x,y;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		cin>>x;
		long long cnt=1,ans=0,cnt1=0,mm=0;
		for(int i=1;i<n;i++){
			cin>>y;
			a[i]=y-x;
			x=y;
			//cout<<a[i];
		}
		a[0]=1e18+7;
		a[n]=1e18+7;
		a[n+1]=1e18+7;
		mm=a[1];
		for(int i=2;i<n-1;i++){
			if(a[i]+a[i-1]<=d&&a[i]+a[i+1]<=d&&a[i-1]+a[i+1]+a[i]>d){
				//cout<<cnt<<' ';
				ans+=cnt*cnt1;
				cnt1=cnt;
				cnt=1;
				
			}
			else if(a[i]>d){
				cnt=1;
				mm=0; 
			}
			else{
				//cout<<i<<' ';
				mm+=a[i];
				if(mm>d){
					mm=a[i];
				}
					cnt++;
			}
		}
		//cout<<ans<<' ';
		
		ans+=cnt*cnt1;
		cout<<ans<<'\n';
	}
	return 0;
}

