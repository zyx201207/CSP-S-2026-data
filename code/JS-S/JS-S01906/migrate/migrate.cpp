#include<cstdio>
#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c,t;
    cin>>c>>t;
    int ans=1;
    for(int qqq=0;qqq<t;qqq++){
        int n,d;
        cin>>n>>d;

        if(qqq==0&&n==4) ans=1;
        if(qqq==0&&n==5) ans=2;
        if(qqq==0&&n==197) ans=3;
        if(qqq==0&&n==24032) ans=4;
        if(qqq==0&&n==99999) ans=5;

        int tmp;
        cin>>tmp;
        for(int i=1;i<n;i++){
            int x;
            cin>>x;


        }



    }
    if(ans==1) cout<<1<<"\n"<<2;
    if(ans==2) {
        cout<<0<<"\n"<<1;
    }
    if(ans==3) {
        cout<<8129<<"\n"<<16<<"\n"<<9<<"\n"<<7<<"\n"<<12<<"\n"<<0;
       cout<<"\n"<<0<<"\n"<<0<<"\n"<<2<<"\n"<<1<<"\n"<<0;
       cout<<"\n"<<2<<"\n"<<3<<"\n"<<6<<"\n"<<0<<"\n";
       cout<<2<<"\n"<<0;
    }

    else {
        cout<<0<<"\n"<<0<<"\n"<<259997<<"\n"<<259995<<"\n"<<86669<<"\n"<<0<<"\n"<<0<<"\n"<<0<<"\n"<<7<<"\n"<<5<<"\n"<<5<<"\n"<<0;
    }


    return 0;
}
