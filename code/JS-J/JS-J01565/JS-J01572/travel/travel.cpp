#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,c2,s1,s2;
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>c2>>s1>>s2;
    if(c1==s1){
        cout<<1;
        bool e=0;
        for(int i=0;i<2;i++){
            if(c2[i]!=s2[i]){
                e=1;
            }
        }
        if(e==0){
            cout<<1;
            if(c2[2]>'C'&&s2[2]>'C'){
                cout<<1<<1;
            }
            else if(c2[2]<'D'&&s2[2]<'D'){
                cout<<1;
                if(abs(c2[2]-s2[2])==1){
                    cout<<1;
                }
                else{
                    cout<<0;
                }
            }
            else{
                cout<<0<<0;
            }
        }
        else{
            cout<<0<<0<<0;
        }
    }
    else{
        cout<<0<<0<<0<<0;
    }
    return 0;
}
