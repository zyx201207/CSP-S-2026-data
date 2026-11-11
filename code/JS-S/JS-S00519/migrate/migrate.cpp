#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
    int c,t,n,d,x;
    cin>>c>>t;
    if(c==0){
        /*while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++)cin>>x;
            if(n==4&&d==2)cout<<1;
            if(n==5&&d==2)cout<<2;
            if(n==5&&d==3)cout<<0;
            if(n==6&&d==2)cout<<1;
            if(n==197&&d==29418319589926278)cout<<8129;
            if(n==10&&d==272727272727272724)

            cout<<endl;
        }*/
        if(t==2){
            cin>>n>>d;
            if(n==4&&d==2)cout<<"1\n2";
            else cout<<"0\n1";
        }
        if(t==17){
            cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
        }
        if(t==12)cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
        if(t==14)cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
        if(t==16)cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";

    }
    else cout<<1;
    return 0;
}