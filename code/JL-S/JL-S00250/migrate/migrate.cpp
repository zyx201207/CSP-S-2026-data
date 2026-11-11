#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[200005];
int main(){
	freopen("migrate.in","r",stdin);
        freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			int a;
			cin>>a;
			x[i]=x[i]-x[i-1];
		}
		int d,ans;
		for(int i=1;i<=n;i++){
			if(x[i]==x[i-1])
				ans++;
			else
				if(ans>d) d=ans;
		}
		ans=ans%d-1;
		cout<<ans<<endl;
	}
        return 0;
}

