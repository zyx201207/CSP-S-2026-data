#include<iostream>
#include<cmath>
#define int long long
using namespace std;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	int c,t;
	cin>>c>>t;
	while(t--){
		int d,s,ans=0,way=0;
		cin>>d>>s;
		int a[d+1];
		way=a[2]-a[1];
		for(int i=1;i<=d;i++)cin>>a[i];
		for(int i=1;i<=d;i++){
			for(int j=i+1;j<=d;j++){
				if(a[j]-a[i]>s and j-1==i){
					d=i;
					ans++;
				}
				if(a[j]-a[i]!=way){
					cout<<0<<"\n";
					continue;
				}
			}
			if(c<=2 and t%2==0)cout<<c/t; 
			else if(c<=2 and t%2==1)cout<<c/t+1;
			else cout<<c/t-1;
		}
	}
	return 0;
}
