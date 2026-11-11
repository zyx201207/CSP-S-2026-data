#include<bits/stdc++.h>
using namespace std;
int n,d,c,t;
int x[2000003],cut[20003][20003],len[5001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		bool flag=true;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i>=3){
				if(x[i]-x[i-1]!=x[i-1]-x[i-2])flag=false;
			}
		}
		if(flag){
			int s=d/(x[2]-x[1]);
			if(s*(x[2]-x[1])==d&&s==1){
				cout<<0<<endl;
				continue;
			}
			if((x[n]-x[1])%d==0&&s*(x[2]-x[1])==d){
				cout<<0<<endl;
				continue;
			}
			if(s<2){
				cout<<0<<endl;
				continue;
			}
			else{
				int ans=0;
				for(int i=1;i<s;i++){
					int f=s-i;
					int g=s+f+1;
					ans+=(n-g+1);
				}
				cout<<ans<<endl;
			}
		}
	
	}
}
