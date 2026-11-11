#include<bits/stdc++.h>
using namespace std;
queue <int>q;
int n,d,c,t,a[2000005],ans=0;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int cha=a[2]-a[1];
		if(cha*2<=d&&d<cha*3){
			if(n<4)ans=0;
			else ans=n-3;
		}else ans=0;
		cout<<ans;
		
	}
	return 0;
}
