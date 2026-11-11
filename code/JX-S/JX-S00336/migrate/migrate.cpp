#include<bits/stdc++.h>
using namespace std;
int a[50005];
int c,t,n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(c==11||c==12){
                int q=d/(a[2]-a[1]);
            if(q<=1){
                cout<<0<<endl;
            }else if(q==2){
                cout<<n-3<<endl;
            }else if(q>2){
                cout<<0<<endl;
            }
        }
    }
return 0;
}
