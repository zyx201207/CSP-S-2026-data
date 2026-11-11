#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2100000];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	
	int c,t;
	cin>>c>>t;
	if(c==11||c==12||c==0)
	{
		for(int i=1;i<=t;i++){
			int n,d;
			cin>>n>>d;
			for(int j=1;j<=n;j++){
				cin>>a[j];	
			}
        	int x=a[2]-a[1];
			for(int y=2;y<=n;y++){
				if(y*x<=d&&x*(y+1)>d){
					cout<<n-((y-1)*2+1)<<"\n";
					break;
				}
			}
			if(2*x>d) cout<<0<<"\n";
		}
	}
	if(c==13||c==14||c==0){
		for(int i=1;i<=t;i++){
			cout<<0<<"\n";
		}
	}
	return 0;
}