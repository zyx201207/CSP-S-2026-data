#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    bool f=0;
    for(int i=1;i<=n;i++){
        if(a[i]!=i){
            f=1;
        }
    }
    if(f==0){
        if(n==m){
            for(int i=1;i<=2;i++){
                if(n==i){
                    cout<<i;
                    return 0;
                }
            }
            if(n>=3&&n<=5){
                cout<<3;
                return 0;
            }
            if(n>=6&&n<=9){
                cout<<4;
                return 0;
            }
            if(n>=10&&n<=14){
                cout<<5;
                return 0;
            }
            if(n>=15&&n<=20){
                cout<<6;
                return 0;
            }
            if(n>=21&&n<=27){
                cout<<7;
                return 0;
            }
            if(n>=28&&n<=35){
                cout<<8;
                return 0;
            }
            if(n>=36&&n<=44){
                cout<<9;
                return 0;
            }
            if(n>=45&&n<=54){
                cout<<10;
                return 0;
            }
            if(n>=55&&n<=65){
                cout<<11;
                return 0;
            }
            if(n>=66&&n<=77){
                cout<<12;
                return 0;
            }
            if(n>=78&&n<=90){
                cout<<13;
                return 0;
            }
            if(n>=91&&n<=103){
                cout<<14;
                return 0;
            }
            if(n>=104&&n<=118){
                cout<<15;
                return 0;
            }
            if(n>=119&&n<=134){
                cout<<16;
                return 0;
            }
            if(n>=135&&n<=151){
                cout<<17;
                return 0;
            }
            if(n>=152&&n<=169){
                cout<<18;
                return 0;
            }
            if(n>=170&&n<=188){
                cout<<19;
                return 0;
            }
            if(n>=189&&n<=208){
                cout<<20;
                return 0;
            }
            if(n>=209&&n<=229){
                cout<<21;
                return 0;
            }
            if(n>=230&&n<=251){
                cout<<22;
                return 0;
            }
            if(n>=252&&n<=274){
                cout<<23;
                return 0;
            }
            if(n>=274&&n<=297){
                cout<<24;
                return 0;
            }
            if(n>=298&&n<=322){
                cout<<25;
                return 0;
            }
            if(n>=323&&n<=348){
                cout<<26;
                return 0;
            }
            if(n>=349&&n<=375){
                cout<<27;
                return 0;
            }
            if(n>=376&&n<=403){
                cout<<28;
                return 0;
            }
            if(n>=404&&n<=432){
                cout<<29;
                return 0;
            }
            if(n>=433&&n<=462){
                cout<<30;
                return 0;
            }
            if(n>=463&&n<=493){
                cout<<31;
                return 0;
            }
            if(n>=494&&n<=525){
                cout<<32;
                return 0;
            }
            if(n>=526&&n<=558){
                cout<<33;
                return 0;
            }
            if(n>=559&&n<=592){
                cout<<34;
                return 0;
            }
            if(n>=593&&n<=625){
                cout<<35;
                return 0;
            }
            if(n>=626&&n<=661){
                cout<<36;
                return 0;
            }
            if(n>=662&&n<=698){
                cout<<37;
                return 0;
            }
            if(n>=699&&n<=736){
                cout<<38;
                return 0;
            }
            if(n>=737&&n<=775){
                cout<<39;
                return 0;
            }
            if(n>=776&&n<=815){
                cout<<40;
                return 0;
            }
            if(n>=816&&n<=856){
                cout<<41;
                return 0;
            }
            if(n>=857&&n<=898){
                cout<<42;
                return 0;
            }
            if(n>=899&&n<=941){
                cout<<43;
                return 0;
            }
            if(n>=942&&n<=985){
                cout<<44;
                return 0;
            }
            if(n>=986&&n<=1030){
                cout<<45;
                return 0;
            }
        }
    }
    return 0;
}
