#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c,d;
    char s,k;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>s;
    cin>>c>>d>>k;
    if(a==c){
        cout<<1;
        if(b==d){
            cout<<1;
            if(s=='A' or s=='B' or s=='C' ){
                if(k=='D' or k=='F'){
                    cout<<0<<0;
                }else{
                    cout<<1;
                    if(s-k==1 or k-s==1){
                        cout<<1;

                    }else{
                        cout<<0;
                    }
                }
            }else{
                if(k=='A' or k=='B' or k=='C' ){
                    cout<<0;
                }else{
                    cout<<1<<1;
                }
            }
        }else{
            cout<<0<<0<<0;
        }

    }else{
        cout<<0<<0<<0<<0;
    }

    return 0;
}
