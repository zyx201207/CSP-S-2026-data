#include<bits/stdc++.h>
using namespace std;
long long n,d;
long long mp[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
//		cout<<n<<d<<" ";
		for(int i=1;i<=n;i++){
//			cout<<"sb";
			cin>>mp[i];
		}
		int tot=0,x=0,y=0;
		
		for(int i=1;i<=n-3;i++){
			if(mp[i+3]-mp[i]>d&&mp[i+2]-mp[i]<=d&&mp[i+3]-mp[i+1]<=d){
				tot++;
				ans++;
//				cout<<i<<" ";
			}
			if(tot==0){
				if(x==0){
					x++;
				}
				else{
					y++;
				}
			}
			if(tot==1){
				ans+=x*y;
				x=0;
				y=0;
			}
			if(tot>1){
				x=0;
				y=0;
			}
			if(mp[i]-mp[i-3]>d&&mp[i]-mp[i-2]<=d&&mp[i-1]-mp[i-3]<=d){
				tot--;
			}
		}
		cout<<ans<<"\n";
	}
}
/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

*/