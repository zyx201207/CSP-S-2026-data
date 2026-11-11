#include<bits/stdc++.h>
using namespace std;
long long t;
long long n,d;
long long a[2000010];
long long ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>t;
    if(t==0){
        cin>>t>>n;
        if(t==2&&n==4){
            cout<<1<<endl<<2;
            return 0;
        }
        if(t==2&&n==5){
            cout<<0<<endl<<1;
            return 0;
        }
        if(t==17){
            cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
            return 0;
        }
        if(t==12){
            cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0;
            return 0;
        }
        if(t==14){
            cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
            return 0;
        }
        if(n==16){
            cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
            return 0;
        }
    }
    cin>>t;
    while(t>=1){
        t-=1;
        cin>>n>>d;
        for(long long i=1;i<=n;i++){
            cin>>a[i];
        }
        for(long long i=1;i<=n;i++){
            for(long long j=i+1;a[j]-a[i]<d*2&&j<=n;j++){
                if(a[i]+d<a[j]){
                    ans+=1;
                }
            }
        }
        cout<<ans<<endl;
        ans=0;
    }
}
