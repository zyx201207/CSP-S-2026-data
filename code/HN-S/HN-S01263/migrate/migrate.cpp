#include<bits/stdc++.h>
using namespace std;
int const N=2e6+10;
int an[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		int tl=1;
		for(int i=1;i<=n;i++){
			cin>>an[i];
			if(i==1) continue;
			if(i==2) tl=an[2]-an[1];
			if(an[i]-an[i-1]==tl) continue;
			tl=-1;
		}
		if(tl!=-1){
			int a=d/tl;
			n--;
			if(a==0){
				cout<<0<<endl;
				continue;
			}
			if(n%a==0){
				cout<<0<<endl;
				continue;
			}
			if(a>n){
				cout<<0<<endl;
				continue;
			}
			int ans=0;
			for(int i=a+1;i<2*a;i++){
				ans+=n-i+1;
			}
			cout<<ans<<endl;
		}
		else cout<<0<<endl;
	}
	return 0;
}
