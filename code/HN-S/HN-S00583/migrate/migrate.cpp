#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
    freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	while(t>0){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int d1=a[3]-a[2];
        int k=d/d1;
        if(k>1){
            int ans=n-(k*2-1);
            cout<<ans<<endl;
        }else cout<<0<<endl;
        t--;
	}
	return 0;
}

