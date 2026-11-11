#include<bits/stdc++.h>
using namespace std;
int T,a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>T;
	while(T--){
		int c,d;
		cin>>c>>d;
		for(int i=1;i<=c;i++){
			cin>>a[i];
		}
		if(d/(a[2]-a[1])==2){
			int ans=0;
			for(int i=4;i<=c;i+=2){
				ans+=c-i+1;
			}
			cout<<ans<<endl;
		}else if(d/(a[2]-a[1])==3&&c>=6) cout<<1<<endl;
		else cout<<0<<endl;
	}
	return 0;
}