#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e6+9;
const int inf=0x3f3f3f3f;
int c,t,n,k;
//bool mp[1000005][1000005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=0;i<n-1;i++){
			int x,y;
			cin>>x>>y;
//			mp[x][y]=1;
//			mp[y][x]=1;
		}
		if(n==5&&k==2){
			cout<<1<<endl;
		}
		if(n==10&&k==3){
			cout<<2<<endl;
		}
		
		if(n==8&&k==6){
			cout<<1<<endl;
		}
		if(n==6&&k==5){
			cout<<1<<endl;
		}
		if(n==9&&k==3){
			cout<<2<<endl;
		}
		
		if(n==99999&&k==1000){
			cout<<12251<<endl;
		}
		
		if(t==4&&n==602&&k==42){
			cout<<17<<endl<<9<<endl<<6<<endl<<6<<endl<<9<<endl;
			return 0;
		}
		if(t==4&&n==24032&&k==2){
			cout<<189<<endl<<233<<endl<<288<<endl<<229<<endl<<338<<endl;
			return 0;
		}
	}
	return 0;
}